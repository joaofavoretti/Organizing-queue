/**
 * Header file for IO-Operations.c functions
 */

#ifndef _IO_OPERATIONS_H
#define _IO_OPERATONS_H


#include <main.h>

/**
 * IO-Operations.c
 */
int command_ENTRY(char *s);
int command_EXIT(char *s);

int isCharValid(char c);
char *allocStringInMemory(FILE *stream);


#endif