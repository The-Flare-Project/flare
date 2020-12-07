#define SERIAL 0
#define VGA_SCREEN 1
#define VGA_AND_SERIAL 2

void term_type(int type);
void term_write(char data[]);