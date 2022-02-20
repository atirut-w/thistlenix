#ifndef COMPMAPPER_H
#define COMPMAPPER_H

// Retrieve the status of the last executed command
char get_cmd_status();

// Execute a command
void exec_cmd(char cmd);

// Get command info
char get_cmd_info();

// Set component selector
void set_component_sel(char sel);

// Read data from command result buffer
char read_result_buffer();

// Write TSF(Thistle Serialized Format) data into command arguments buffer
void write_result_buffer(char data);

// Get current bank mask
char get_bank_mask();

// Modify memory bank masking
void set_bank_mask(char mask);

// TODO: Command flag and available memory banks

#endif
