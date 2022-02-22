#ifndef _PEEKPOKE_H
#define _PEEKPOKE_H

#define PEEK(addr) (*(unsigned char *)(addr))
#define POKE(addr, data) (*(unsigned char *)(addr) = (data))

#endif
