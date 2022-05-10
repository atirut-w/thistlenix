#include "peekpoke.h"
#include "basicio.h"
#include "memory.h"
#include "component.h"
#include "interrupt.h"

// void irq() {
//     DISABLE_IRQ();

//     // print("Kernel heap space used: $");
//     // printshort(get_used_memory());
//     // print(" bytes($");
//     // printshort(get_free_memory());
//     // print(" bytes free)\n");

//     //ptr = kmalloc(256);

//     // Reset timer
//     POKE(0xe05a, 1);
//     POKE(0xe05b, 0);

//     ENABLE_IRQ();
//     RTI();
// }

void show_components() {
    component_data_t data;
    char count;
    char i;
    char j;

    count = get_component_count();

    for (i = 0; i < count; i++) {
        get_component_info(&data, i);

        for (j = 0; j < 16; j++) {
            printhex(data.uuid[j]);
        }
        print("    ");
        print(data.type);
        print("\n");
    }
}

void main() {
    initialize_kernel_heap();
    show_components();

    // // Set up IRQ handler
    // SET_HANDLER(0xfffe, irq);

    // // Set up timer to trigger IRQ every tick(1/20 s)
    // POKE(0xe05a, 1);
    // POKE(0xe05b, 0);
    // POKE(0x0e05e, 1);

    print("OK\n");
    while (1) {}
}
