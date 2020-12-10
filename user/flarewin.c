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
	draw_window(KNO_STDWIN);

	drawbg();

	drawWin(100, 100, 300, 200, "Demo`s");
	draw_flush();

	return 0;
}