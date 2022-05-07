#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

#include "peekpoke.h"

#define ENABLE_IRQ() __asm__("cli")
#define DISABLE_IRQ() __asm__("sei")
#define RTI() __asm__("rti")
#define SET_HANDLER(vector_address, handler_address) \
    POKE(vector_address, (unsigned short)handler_address & 0xff); \
    POKE(vector_address + 1, (unsigned short)handler_address >> 8)

#endif
