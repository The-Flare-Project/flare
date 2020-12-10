#include "library/syscalls.h"
#include "library/string.h"
#include "library/user-io.h"
#include "kernel/types.h"
#include "library/flareui.h"

#define H 800
#define W 600

int drawWin(int x, int y, int h, int w, char title[]){
	draw_color(44,44,44);
	draw_rect(x - 1, y - 1, h + 2, w + 2);

	draw_color(0, 0, 0);
	draw_rect(x, y, h, w);

	draw_color(32,32,32);
	draw_rect(x, y, h, 18);

	draw_color(245,245,245);
	draw_string(x + 4, y + 6, title);

	//draw_line(x, y, h, w - (w - 20));
}
int drawbg(){
	draw_color(27,27,27);
	draw_rect(0, 0, H, W);
	draw_color(255,255,255);
	draw_line(0, 0, H, W);
	draw_string(10, 10, "Flare Dev Version (dev.0.1)");
}