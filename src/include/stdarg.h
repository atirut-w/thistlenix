#ifndef STDARG_H
#define STDARG_H

typedef unsigned char* va_list;

#define va_start(ap, fix)       ap = ((va_list)&(fix))
#define va_arg(ap,type)         (*(type*)(ap -= ((sizeof (type) + 1) & ~1)))
#if __CC65_STD__ >= __CC65_STD_C99__
#define va_copy(dest, src)      ((dest)=(src))
#endif
#define va_end(ap)

#endif
