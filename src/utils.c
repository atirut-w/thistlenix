#include "include/utils.h"
#include <stdlib.h>

void print(const char *message) {
    while (*message) {
        *(char *)0xe003 = *message++;
    }
}
