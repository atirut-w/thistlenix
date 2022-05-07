#include "memory.h"
#include "config.h"
#include "basicio.h"
#include "halt.h"

malloc_header_t *kernel_heap = (malloc_header_t *)KERNEL_HEAP_BEGIN;

void initialize_kernel_heap() {
    kernel_heap->size = 0x9fff - KERNEL_HEAP_BEGIN;
    kernel_heap->used = 0;
    print("Initialized kernel heap at $");
    printhex(KERNEL_HEAP_BEGIN >> 8);
    printhex(KERNEL_HEAP_BEGIN & 0xff);
    print("\n");
}

void *kmalloc(unsigned short size) {
    unsigned short realsize;
    malloc_header_t *chunk, *other;

    if ((realsize = sizeof(malloc_header_t) + size) < KMALLOC_MINSIZE) {
        realsize = KMALLOC_MINSIZE;
    }

    chunk = kernel_heap;
    while (chunk->used || chunk->size < realsize) {
        if (chunk->size == 0) {
            print("Corrupted chunk with null size at $");
            printhex((unsigned short)chunk >> 8);
            printhex((unsigned short)chunk & 0xff);
            print("\n");
            halt();
        }

        chunk = (malloc_header_t *)((char *)chunk + chunk->size);

        if (chunk == kernel_heap) {
            print("Out of memory\n");
            halt();
        }
    }

    if (chunk->size - realsize < KMALLOC_MINSIZE) {
        chunk->used = 1;
    } else {
        other = (malloc_header_t *)((char *)chunk + realsize);
        other->size = chunk->size - realsize;
        other->used = 0;

        chunk->size = realsize;
        chunk->used = 1;
    }

    kernel_heap->used += realsize;
    return (char *)chunk + sizeof(malloc_header_t);
}

void kfree(void *ptr) {
    malloc_header_t *chunk, *other;

    if (ptr == 0) {
        return;
    }

    chunk = (malloc_header_t *)((char *)ptr - sizeof(malloc_header_t));
    chunk->used = 0;

    kernel_heap->used -= chunk->size;

    while ((other = (malloc_header_t *)((char *)chunk + chunk->size))
            && other < kernel_heap
            && other->used == 0)
    {
        chunk->size += other->size;
    }
}
