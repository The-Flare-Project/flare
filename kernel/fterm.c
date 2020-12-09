#include "fterm.h"
#include "serial.h"
#include "printf.h"
#include "string.h"

int TYPE = 0;

void term_type(int type){
    TYPE = type;
}
void term_write(char data[]){
    switch (TYPE)
    {
    case 0:
        printf("%x: %s", strlen(data), "lol");
        serial_write(0, data[0]);
        break;
    
    case 1:
        printf(data);
        break;
    }
}