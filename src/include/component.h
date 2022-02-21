#ifndef COMPOENENT_H
#define COMPOENENT_H

struct componentinfo {
    unsigned char uuid[16];
    char name[16];
};

// Get the number of connected components.
char get_component_count();

// List components.
struct componentinfo *list_components();

#endif
