#ifndef _COMPONENT_H
#define _COMPONENT_H

typedef struct componentdata {
    char uuid[16];
    char name[16];
} componentdata_t;

void list_component(componentdata_t *buffer);

#endif
