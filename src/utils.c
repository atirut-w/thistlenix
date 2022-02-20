#include "include/utils.h"
#include <stdlib.h>

void print(const char *message) {
    while (*message) {
        *(char *)0xe003 = *message++;
    }
}

void log(const char *message) {
    char timestamp[32];
    itoa(get_uptime() / 20, timestamp, 10);
    print("[");
    print(timestamp);
    print("] ");
    print(message);
    print("\n");
}

int get_uptime() {
    return *(int *)0xe058;
}
