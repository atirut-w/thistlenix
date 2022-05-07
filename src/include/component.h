#ifndef _COMPONENT_H_
#define _COMPONENT_H_

// Information about a component.
typedef struct {
    unsigned char uuid[16];
    unsigned char type[32];
} component_data_t;

char list_components(component_data_t *buffer);

#endif
