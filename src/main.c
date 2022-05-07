#include "peekpoke.h"
#include "basicio.h"
#include "memory.h"
#include "component.h"
#include "interrupt.h"

void irq() {
    DISABLE_IRQ();

    print("Current uptime in ticks: $");
    printhex(PEEK(0xe059));
    printhex(PEEK(0xe058));
    print("\n");

    // Reset timer
    POKE(0xe05a, 20);
    POKE(0xe05b, 0);

    ENABLE_IRQ();
    RTI();
}

void main() {
    component_data_t *components;
    char compcount;
    char i;

    initialize_kernel_heap();
    components = (component_data_t *)kmalloc(sizeof(component_data_t) * 16);

    compcount = list_components(components);
    for (i = 0; i < compcount; i++) {
        print(components[i].type);
        print("\n");
    }

    kfree(components);

    // Set up IRQ handler
    SET_HANDLER(0xfffe, irq);

    // Set up timer to trigger IRQ every tick(1/20 s)
    POKE(0xe05a, 20);
    POKE(0xe05b, 0);
    POKE(0x0e05e, 1);

    print("OK\n");
    while (1) {}
}
