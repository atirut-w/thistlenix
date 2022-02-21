#include "include/component.h"
#include "include/peekpoke.h"
#include "include/utils.h"
#include <stdlib.h>

void expect_tag(char expected, char got) {
    if (expected != got) {
        char tmpbuffer[4];

        print("Expected tag ");
        print(itoa(expected, tmpbuffer, 10));
        print(" but got ");
        print(itoa(got, tmpbuffer, 10));
        print("\n");
        
        while (1) {}
    }
}

char get_component_count() {
    POKE(0xE010, 3);
    return PEEK(0xE011);
}

struct component *list_components() {
    struct component components[16];
    char component_count, ci;
    char tmpbuffer[4];

    component_count = get_component_count();

    for (ci = 0; ci < component_count; ci++) {
        char tag, si, strlen;

        tag = PEEK(0xE012);
        expect_tag(11, tag);

        for (si = 0; si < 16; si++) {
            components[ci].uuid[si] = PEEK(0xE012);
        }

        tag = PEEK(0xE012);
        expect_tag(10, tag);

        strlen = PEEK(0xE012);
        components[ci].name[0] = PEEK(0xE012); // Quick hack to force the compiler to do another PEEK.
        for (si = 0; si < strlen; si++) {
            components[ci].name[si] = PEEK(0xE012);
        }
        components[ci].name[strlen] = '\0';
    }

    return components;
}
