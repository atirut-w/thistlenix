#include "peekpoke.h"
#include "basicio.h"

void irq() {
    __asm__("rti");
}

void nmi() {
    print("Current uptime in ticks: $");
    printhex(PEEK(0xe059));
    printhex(PEEK(0xe058));
    print("\n");

    // Reset timer
    POKE(0xe05a, 1);
    POKE(0xe05b, 0);

    __asm__("rti");
}

void main() {
    // Set up IRQ and NMI handlers
    POKE(0xfffe, (unsigned short)irq & 0xff);
    POKE(0xffff, (unsigned short)irq >> 8);
    POKE(0xfffa, (unsigned short)nmi & 0xff);
    POKE(0xfffb, (unsigned short)nmi >> 8);

    // Set up timer to trigger NMI every tick(1/20 s)
    POKE(0xe05a, 1);
    POKE(0xe05b, 0);
    POKE(0x0e05f, 1);

    print("OK\n");
}
