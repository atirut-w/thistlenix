#ifndef _COMPONENT_H_
#define _COMPONENT_H_

// Information about a component.
typedef struct {
    unsigned char uuid[16];
    unsigned char type[32];
} component_data_t;

// Generic component wrapper.
typedef struct {
    char command;
    char command_io;
    char command_flag;
    char uuid[16];
    char type[32];
    char slot;
} component_t;

char get_component_count();
char list_components(component_data_t *buffer);
component_t *map_component(char *uuid);

#endif
