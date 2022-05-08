#ifndef _CONFIG_H_
#define _CONFIG_H_

#define KERNEL_HEAP_BEGIN 0x2000 // Adjust this if kernel gets bigger than 4KiB
#define KERNEL_HEAP_END 0x9fff // Up to end of bank 9. No support for masking out component access areas yet.
#define KMALLOC_MINSIZE 16

#endif
