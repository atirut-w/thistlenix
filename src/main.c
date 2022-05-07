#include "peekpoke.h"
#include "basicio.h"
#include "component.h"

void main() {
    component_data_t components[16];
    char compcount;
    char i;
    char j;

    compcount = list_components(components);

    print("0x");
    printhex(compcount);
    print(" components found.\n");

    for (i = 0; i < compcount; i++) {
        print("  0x");
        printhex(i);
        print(" ");
        for (j = 0; j < 16; j++) {
            printhex(components[i].uuid[j]);
        }
        print(" ");
        print(components[i].type);
        print("\n");
    }

    print("OK\n");
}
