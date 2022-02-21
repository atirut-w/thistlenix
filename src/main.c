#include <stdlib.h>
#include "include/utils.h"
#include "include/component.h"

void main() {
    char tmpbuffer[16];

    {
        char i;
        char component_count = get_component_count();
        struct component *components = list_components();

        print("Component count: ");
        print(itoa(component_count, tmpbuffer, 10));
        print("\n");

        for (i = 0; i < component_count; i++) {
            print("Component ");
            print(itoa(i, tmpbuffer, 10));
            print(": ");
            print(components[i].name);
            print("\n");
        }
    }
}
