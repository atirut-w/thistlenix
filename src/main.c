#include <stdlib.h>
#include "include/utils.h"
#include "include/compmapper.h"
#include "include/component.h"

void main() {
    print("Listing components...\n");

    {
        char i, component_count, tmpbuffer[16];
        struct component *components;

        components = list_components();
        component_count = get_component_count();

        for (i = 0; i < component_count; i++) {
            print("Component ");
            print(components[i].name);
            print("\n");
        }
    }
}
