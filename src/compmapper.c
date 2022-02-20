#include "include/compmapper.h"

char get_cmd_status() {
    return *(char *)0xe010;
}

void exec_cmd(char cmd) {
    *(char *)0xe010 = cmd;
}

char get_cmd_info() {
    return *(char *)0xe011;
}

void set_component_sel(char sel) {
    *(char *)0xe011 = sel;
}

char read_result_buffer() {
    return *(char *)0xe012;
}

void write_result_buffer(char data) {
    *(char *)0xe012 = data;
}

char get_bank_mask() {
    return *(char *)0xe01a;
}

void set_bank_mask(char mask) {
    *(char *)0xe01a = mask;
}
