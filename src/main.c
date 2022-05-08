#include "peekpoke.h"
#include "basicio.h"
#include "memory.h"
#include "component.h"
#include "interrupt.h"

char *ptr = (char *)0;
char *ptr2 = (char *)0;

void irq() {
    DISABLE_IRQ();

    // print("Kernel heap space used: $");
    // printshort(get_used_memory());
    // print(" bytes($");
    // printshort(get_free_memory());
    // print(" bytes free)\n");

    //ptr = kmalloc(256);

    // Reset timer
    POKE(0xe05a, 1);
    POKE(0xe05b, 0);

    ENABLE_IRQ();
    RTI();
}

void show_components() {
    char compcount;
    char i;
    char j;
    component_data_t *components;

    compcount = get_component_count();
    components = kmalloc(compcount * sizeof(component_data_t));
    list_components(components);

    for (i = 0; i < compcount; i++) {
        for (j = 0; j < 16; j++) {
            printhex(components[i].uuid[j]);
        }
        print("  ");
        print(components[i].type);
        print("\n");
    }

    kfree(components);
}

void main() {
    initialize_kernel_heap();
    show_components();

    // Set up IRQ handler
    SET_HANDLER(0xfffe, irq);

    // Set up timer to trigger IRQ every tick(1/20 s)
    POKE(0xe05a, 1);
    POKE(0xe05b, 0);
    POKE(0x0e05e, 1);

    print("OK\n");
    while (1) {}
}
