#include "component.h"
#include "peekpoke.h"
#include "basicio.h"

char mapped_components = 0;

char get_component_count() {
    POKE(0xe010, 3);
    return PEEK(0xe011);
}

char list_components(component_data_t *buffer) {
    char compcount;
    char i;
    char j;
    char tag;
    unsigned short strlen;

    compcount = get_component_count();

    if (buffer == 0) {
        return compcount;
    }

    for (i = 0; i < compcount; i++) {
        tag = PEEK(0xe012);

        for (j = 0; j < 16; j++) {
            buffer[i].uuid[j] = PEEK(0xe012);
            // printhex(buffer[i].uuid[j]);
        }
        // print("    ");

        tag = PEEK(0xe012);
        strlen = PEEK(0xe012);
        strlen += PEEK(0xe012) << 8;

        for (j = 0; j < strlen; j++) {
            buffer[i].type[j] = PEEK(0xe012);
            // POKE(0xe003, buffer[i].type[j]);
        }
        buffer[i].type[strlen] = 0;
        // print("\n");
    }

    return compcount;
}
