#include "peekpoke.h"
#include "basicio.h"
#include "memory.h"
#include "component.h"

void irq() {
    __asm__("sei"); // Disable interrupts while we're in here

    print("Current uptime in ticks: $");
    printhex(PEEK(0xe059));
    printhex(PEEK(0xe058));
    print("\n");

    // Reset timer
    POKE(0xe05a, 20);
    POKE(0xe05b, 0);

    __asm__("cli"); // Enable interrupts again
    __asm__("rti"); // Done
}

void main() {
    component_data_t *components;
    char compcount;
    char i;

    __asm__("sei");

    initialize_kernel_heap();
    components = (component_data_t *)kmalloc(sizeof(component_data_t) * 16);

    compcount = list_components(components);
    for (i = 0; i < compcount; i++) {
        print(components[i].type);
        print("\n");
    }

    kfree(components);

    // Set up IRQ handler
    POKE(0xfffe, (unsigned short)irq & 0xff);
    POKE(0xffff, (unsigned short)irq >> 8);

    // Set up timer to trigger IRQ every tick(1/20 s)
    POKE(0xe05a, 20);
    POKE(0xe05b, 0);
    POKE(0x0e05e, 1);

    print("OK\n");
    __asm__("cli");
    while (1) {}
}
