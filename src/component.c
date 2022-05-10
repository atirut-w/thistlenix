#include "component.h"
#include "peekpoke.h"
#include "basicio.h"

char mapped_components = 0;

char get_component_count() {
    POKE(0xe010, 3);
    return PEEK(0xe011);
}

void get_component_info(component_data_t *data, char index) {
    char count;
    char i;
    char j;
    char tag;
    short strlen;

    if (data == 0) {
        return;
    }

    count = get_component_count();
    if (index >= count) {
        return;
    }

    for (i = 0; i < count; i++) {
        tag = PEEK(0xe012);

        for (j = 0; j < 16; j++) {
            data->uuid[j] = PEEK(0xe012);
        }

        tag = PEEK(0xe012);
        strlen = PEEK(0xe012);
        strlen += PEEK(0xe012) << 8;

        for (j = 0; j < strlen; j++) {
            data->type[j] = PEEK(0xe012);
        }
        data->type[strlen] = 0;

        if (i == index) {
            return;
        }
    }
}
