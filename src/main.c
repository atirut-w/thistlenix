#include <stdlib.h>
#include "include/utils.h"
#include "include/compmapper.h"

void main() {
    char tmpbuf[64];

    print("Listing components...\n");
    exec_cmd(3);

    if (get_cmd_status() != 0x0) {
        print("Bad IO\n");
    }

    print("Component count: ");
    itoa(get_cmd_info(), tmpbuf, 10);
    print(tmpbuf);
}
