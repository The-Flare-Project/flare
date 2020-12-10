/*
Copyright (C) 2015-2019 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#include "console.h"
#include "page.h"
#include "process.h"
#include "interrupt.h"
#include "keyboard.h"
#include "mouse.h"
#include "clock.h"
#include "ata.h"
#include "device.h"
#include "cdromfs.h"
#include "string.h"
#include "graphics.h"
#include "kernel/ascii.h"
#include "kernel/syscall.h"
#include "rtc.h"
#include "kernelcore.h"
#include "kmalloc.h"
#include "memorylayout.h"
#include "kshell.h"
#include "cdromfs.h"
#include "diskfs.h"
#include "serial.h"
#include "fterm.h"
#include "library/flareui.h"

static int mount( const char *devname, int unit, const char *fs_type)
{
	struct device *dev = device_open(devname,unit);
	if(dev) {
		struct fs *fs = fs_lookup(fs_type);
		if(fs) {
			struct fs_volume *v = fs_volume_open(fs,dev);
			if(v) {
				struct fs_dirent *d = fs_volume_root(v);
				if(d) {
					if(current->root_dir) fs_dirent_close(current->root_dir);
					current->root_dir = d;
					current->current_dir = fs_dirent_addref(d);
					return 0;
				}
				fs_volume_close(v);
			}
		}
		device_close(dev);
	}
	return -1;
}

/*
This is the C initialization point of the kernel.
By the time we reach this point, we are in protected mode,
with interrupts disabled, a valid C stack, but no malloc heap.
Now we initialize each subsystem in the proper order:
*/

int kernel_main()
{
	struct graphics *g = graphics_create_root();

	console_init(g);
	console_addref(&console_root);

	printf("\n\n");

	term_type(SERIAL);

	term_write("Welcome!");

	printf("\n\n");

	printf("video: %d x %d\n", video_xres, video_yres, video_xbytes);
	printf("kernel: %d bytes\n", kernel_size);

	page_init();
	kmalloc_init((char *) KMALLOC_START, KMALLOC_LENGTH);
	interrupt_init();
	rtc_init();
	clock_init();
	mouse_init();
	keyboard_init();
	process_init();
	ata_init();
	cdrom_init();
	diskfs_init();

	printf("Mounting cdromfs...\n");
	mount("atapi",2,"cdromfs");
	printf("Mounted! Running shell...\n");

	serial_write(0, 'U');
	serial_write(0, 's');
	serial_write(0, 'i');
	serial_write(0, 'n');
	serial_write(0, 'g');

	serial_write(0, ' ');

	serial_write(0, 'v');
	serial_write(0, 'g');
	serial_write(0, 'a');

	serial_write(0, ' ');

	serial_write(0, 's');
	serial_write(0, 'c');
	serial_write(0, 'r');
	serial_write(0, 'e');
	serial_write(0, 'e');
	serial_write(0, 'n');

	char sh[] = "bin/flarewin.fapp";

	int pid = sys_process_run(sh, 0, "");
	if(pid > 0) {
		printf("\n\n");
		process_yield();
	} else {
		printf("Failed to run shell :(\n");
		printf("Running kernel shell...\n");
		kshell_launch();
	}

	while(1) {
		//console_putchar(&console_root,keyboard_read(0));
	}

	return 0;
}
