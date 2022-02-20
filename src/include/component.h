#ifndef COMPONENT_H
#define COMPONENT_H

struct component {
    char uuid[16];
    char name[32];
};

// List connected components
struct component *list_components();

#endif
