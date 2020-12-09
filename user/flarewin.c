/*
Copyright (C) 2016-2019 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/


#include "library/syscalls.h"
#include "library/string.h"
#include "library/user-io.h"
#include "library/flareui.h"
#include "kernel/types.h"

/*
	Display time in a window
*/


int main(int argc, char *argv[])
{
	int CLOCK_W = 100;
	int CLOCK_H = 100;

	/* Set up window  */
	draw_window(KNO_STDWIN);
	draw_clear(0, 0, CLOCK_W, CLOCK_H);
	draw_color(27,27,27);
	draw_rect(0, 0, 1000, 1000);

	drawWin(100, 100, 200, 200, "Demo`s");
	draw_flush();

	return 0;
}