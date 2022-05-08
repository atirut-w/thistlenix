#ifndef _MEMORY_H_
#define _MEMORY_H_

// Metadata about a memory block.
typedef struct malloc_header {
    unsigned short size; // Size of the block, including the header.
    unsigned char used;  // Whether the block is used.
    struct malloc_header *next; // Pointer to the next block.
} malloc_header_t;

// Initialize the kernel heap.
void initialize_kernel_heap();
// Allocate a block of memory.
void *kmalloc(unsigned short size);
// Free a block of memory.
void kfree(void *ptr);
// Get the amount of memory used by the kernel heap.
short get_used_memory();
// Get the amount of memory free in the kernel heap.
short get_free_memory();

#endif
