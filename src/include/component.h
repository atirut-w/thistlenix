#ifndef COMPONENT_H
#define COMPONENT_H

struct component {
    char uuid[16];
    char name[16];
};

// Get the amount of components
char get_component_count();
// List connected components
struct component *list_components();

#endif
