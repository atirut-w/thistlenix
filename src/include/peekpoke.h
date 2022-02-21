#ifndef PEEKPOKE_H
#define PEEKPOKE_H

#define PEEK(addr) (*(unsigned char *)(addr))
#define POKE(addr, value) (*(unsigned char *)(addr) = (value))

#endif
