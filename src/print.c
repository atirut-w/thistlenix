#include "print.h"

void print(const char *msg) {
    while (*msg) {
        POKE(0xE003, *msg++);
    }
}
