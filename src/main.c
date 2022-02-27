#include "peekpoke.h"
#include "print.h"

void main() {
    print("OK\n");
    while (1) {
        char avail = PEEK(0xE000);

        if (avail > 0) {
            char c = PEEK(0xE001);

            if (c == 0) {
                c = PEEK(0xE001); // Discard
            } else {
                POKE(0xE003, c);
            }
        }
    }
}
