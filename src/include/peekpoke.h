#ifndef _PEEKPOKE_H_
#define _PEEKPOKE_H_

#define PEEK(addr) (*(unsigned char *)(addr))
#define POKE(addr, data) (*(unsigned char *)(addr) = (data))

#endif
