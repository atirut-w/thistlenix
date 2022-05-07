#include "basicio.h"
#include "peekpoke.h"

void print(const char *msg) {
    while (*msg) {
        POKE(0xE003, *msg++);
    }
}

void printhex(unsigned char val) {
    char hex[] = "0123456789abcdef";

    POKE(0xE003, hex[val >> 4]);
    POKE(0xE003, hex[val & 0xF]);
}
