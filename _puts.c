//#include "main.h"
#include <stdio.h>

void _putchar(char c, void *count);

int
_strlen(char *s)
{
    int i;

    for (i = 0; s[i]; i++)
        ;

    return (i);
}

/**
 * _puts - prints a string
 * @str: string to print
 * @count: pointer to count of characters printed
 */
void _puts(char *str, void *count)
{
    // todo: handle the case where str is NULL
    while (*str)
        _putchar(*str++, count);
}
