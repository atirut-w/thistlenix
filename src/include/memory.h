#ifndef _MEMORY_H_
#define _MEMORY_H_

typedef struct {
    unsigned short size;
    unsigned short used;
} malloc_header_t;

void initialize_kernel_heap();
void *kmalloc(unsigned short size);
void kfree(void *ptr);

#endif
