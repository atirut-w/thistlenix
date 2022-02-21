#include "include/component.h"
#include "include/peekpoke.h"

char get_component_count() {
    POKE(0xE010, 3);
    return PEEK(0xE011);
}
