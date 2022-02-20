#include <stdlib.h>
#include "include/utils.h"
#include "include/compmapper.h"

void main() {
    char tmpbuf[64];
    char component_count;

    print("Listing components...\n");
    exec_cmd(3);

    if (get_cmd_status() != 0x0) {
        print("Bad IO\n");
    }

    component_count = get_cmd_info();

    print("Component count: ");
    print(itoa(component_count, tmpbuf, 10));
    print("\n");
}
