#include "memory.h"
#include "config.h"
#include "basicio.h"
#include "halt.h"

malloc_header_t *kernel_heap = (malloc_header_t *)KERNEL_HEAP_BEGIN;

void initialize_kernel_heap() {
    kernel_heap->size = KERNEL_HEAP_SIZE;
    kernel_heap->used = 0;
    kernel_heap->next = 0;
    print("Initialized kernel heap at $");
    printshort(KERNEL_HEAP_BEGIN);
    print("\n");
}

void *kmalloc(unsigned short size) {
    malloc_header_t *block, *next;

    if (size == 0) {
        return 0;
    }

    block = kernel_heap;

    while (block->used) {
        if (block->size == 0) {
            print("Corrupted block metadata at $");
            printshort(block);
            print(".\n");
            halt();
        }

        block = block->next;

        if ((unsigned short)block > KERNEL_HEAP_END) {
            print("Out of memory.\n");
            halt();
        }
    }

    block->size = sizeof(malloc_header_t) + size;
    block->used = 1;
    block->next = next = block + block->size;

    next = block->next;
    next->size = KERNEL_HEAP_END - (unsigned short)next;
    next->used = 0;
    next->next = 0;

    return block + sizeof(malloc_header_t);
}

void kfree(void *ptr) {
    malloc_header_t *block, *next;
    block = kernel_heap; // TODO: Figure out why I can't use `sizeof()` here.

    while (block + sizeof(malloc_header_t) != ptr) {
        block = block->next;
    }

    next = block->next;

    block->used = 0;

    if (next->used == 0) {
        block->size += next->size;
        block->next = next->next;
    }
}

short get_used_memory() {
    malloc_header_t *block;
    unsigned short total = 0;
    block = kernel_heap;

    while (block->next != 0) {
        if (block->used) {
            total += block->size;
        }
        block = block->next;
    }

    return total;
}

short get_free_memory() {
    return KERNEL_HEAP_SIZE - get_used_memory();
}
