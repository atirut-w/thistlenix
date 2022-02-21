#ifndef PEEKPOKE_H
#define PEEKPOKE_H

#define PEEK(addr) *(volatile unsigned char *)(addr)
#define POKE(addr, data) *(volatile unsigned char *)(addr) = (data)

#endif
