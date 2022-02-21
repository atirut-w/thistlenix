#include "include/utils.h"
#include "include/peekpoke.h"

void print(const char *message) {
    while (*message) {
        POKE(0xE003, *message++);
    }
}
