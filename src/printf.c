#include "include/printf.h"
#include "include/stdarg.h"
#include "include/peekpoke.h"
#include <stdlib.h>

#define PUT(c) POKE(0xE003, c)

int printf(const char *format, ...) {
    va_list args;

    int int_tmp;
    char char_tmp;
    char *str_tmp;
    double double_tmp;

    char ch;
    int length = 0;

    va_start(args, format);

    while (ch = *format++) {
        if (ch == '%') {
            switch (ch = *format++) {
                case '%':
                    PUT('%');
                    length++;
                    break;
                case 'c':
                    char_tmp = (char) va_arg(args, int);
                    PUT(char_tmp);
                    length++;
                    break;
                case 's':
                    str_tmp = va_arg(args, char*);
                    while (*str_tmp) {
                        PUT(*str_tmp++);
                        length++;
                    }
                    break;
                case 'd':
                    int_tmp = va_arg(args, int);
                    str_tmp = itoa(int_tmp, str_tmp, 10);
                    while (*str_tmp) {
                        PUT(*str_tmp++);
                        length++;
                    }
                    break;
            }
        } else {
            PUT(ch);
            length++;
        }
    }

    va_end(args);
    return length;
}
