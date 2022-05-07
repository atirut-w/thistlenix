#include "halt.h"
#include "basicio.h"

void halt() {
    __asm__("sei");
    print("System halted.");
    while (1) {}
}
