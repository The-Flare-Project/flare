/*
Copyright (C) 2016-2019 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

/* Snake Game */
#include "library/string.h"

#include "library/syscalls.h"
#include "library/user-io.h"

/* Main Execution */
int main(int argc, char *argv[])
{
    draw_clear(0, 0, 10000, 10000);
    int red = 1;
    int green = 2;
    int blue = 2;
    for(int i; i < 255; i++){
        draw_color(red, green, blue);
        draw_rect(red, red, 1, 1);
        i++;
        red++;
    }
    syscall_process_wait(syscall_process_yield, 1);
    return 0;
}