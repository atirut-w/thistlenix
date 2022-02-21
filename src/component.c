#include "include/component.h"
#include "include/compmapper.h"
#include "include/utils.h"
#include <stdlib.h>

char tagnames[15][16] = {
    "End",
    "Null",
    "Boolean",
    "Byte",
    "Short",
    "Integer",
    "Long",
    "Double",
    "Fixed",
    "ByteArray",
    "String",
    "UUID",
    "Array",
    "Map",
    "Value"
};

char *lookup_tagname(char tag) {
    if (tag < 0 || tag > 14) {
        return "Unknown";
    }

    return tagnames[tag];
}

void expect_tag(char expected, char actual) {
    if (expected != actual) {
        print("Expected tag ");
        print(lookup_tagname(expected));
        print(" but got ");
        print(lookup_tagname(actual));
        print("\n");

        while (1) {}
    }
}

struct component *list_components() {
    struct component components[16];
    char component_count;

    exec_cmd(3);
    component_count = get_cmd_info();

    {
        char i;

        for (i = 0; i < component_count; i++) {
            char tag, xi;
            unsigned char strlen;

            tag = read_result_buffer();
            expect_tag(11, tag);

            for (xi = 0; xi < 16; xi++) {
                components[i].uuid[xi] = read_result_buffer();
            }

            tag = read_result_buffer();
            expect_tag(10, tag);

            strlen = read_result_buffer();
            read_result_buffer(); // Discard the null byte
            for (xi = 0; xi < strlen; xi++) {
                components[i].name[xi] = read_result_buffer();
                // *(char *)0xe003 = read_result_buffer();
            }
            components[i].name[xi] = 0;
        }
        components[i].name[0] = 0;
    }

    return components;
}
