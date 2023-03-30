#ifndef _MAIN_H
#define _MAIN_H

#include "stdlib.h"
#include "stdio.h"
#include "stdarg.h"

/**
 * struct function_s - structure holding an identifier and a function
 * @identifier: character identifying action
 * @print_function: function excecuted when identifier is identified
*/

typedef struct function_s
{
	char *identifier;
	int (*print_function)(va_list ap);
} function_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list ap);
int printi(va_list ap);
int print_int(int i);
int print_string(va_list ap);
int int_to_binary(int num);
int int_to_bin(va_list ap);

#endif /*_printf*/
