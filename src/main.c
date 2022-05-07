#include "peekpoke.h"
#include "basicio.h"

void irq() {
    __asm__("sei"); // Disable interrupts while we're in here

    print("Current uptime in ticks: $");
    printhex(PEEK(0xe059));
    printhex(PEEK(0xe058));
    print("\n");

    // Reset timer
    POKE(0xe05a, 1);
    POKE(0xe05b, 0);

    __asm__("cli"); // Enable interrupts again
    __asm__("rti"); // Done
}

void main() {
    // Set up IRQ handler
    POKE(0xfffe, (unsigned short)irq & 0xff);
    POKE(0xffff, (unsigned short)irq >> 8);

    // Set up timer to trigger IRQ every tick(1/20 s)
    POKE(0xe05a, 1);
    POKE(0xe05b, 0);
    POKE(0x0e05e, 1);

    print("OK\n");
}
