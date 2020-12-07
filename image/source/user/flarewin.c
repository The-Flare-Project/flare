/*
Copyright (C) 2016-2019 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/


#include "library/syscalls.h"
#include "library/string.h"
#include "library/user-io.h"
#include "kernel/types.h"

/*
	Display time in a window
*/


int main(int argc, char *argv[])
{
	int CLOCK_W = 100;
	int CLOCK_H = 100;
	int thickness = 4;

	/* Set up window  */
	draw_window(KNO_STDWIN);
	draw_clear(0, 0, CLOCK_W, CLOCK_H);
	draw_color(255, 255, 255);
	draw_rect(0, 0, 1000, 1000);

	drawWin(10, 10, 200, 200, "Demo");

	draw_flush();

	/* Run Clock */
	char c = 0;
	while(c != 'q')
	{
		syscall_object_read_nonblock(0, &c, 1);
		syscall_process_sleep(2000);
		draw_flush();

	}

	return 0;
}


int drawWin(int x, int y, int h, int w, char title[]){
	draw_color(0, 0, 0);
	draw_rect(x, y, h, w);

	draw_color(50, 50, 50);
	draw_rect(x, y, h, 20);

	draw_color(255, 255, 255);
	draw_string(x + 4, y + 5, title);

	draw_line(x, y - 3, h - 20, 23);
}