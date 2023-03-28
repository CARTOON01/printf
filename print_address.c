#include "main.h"
#include <stdlib.h>

void _puthex(unsigned long int n, void *count, int upper)
{
    if (n / 16)
        _puthex(n / 16, count, upper);
    _putchar((n % 16) + (n % 16 < 10 ? '0' : 'a' - 10), count);
}

/**
 * print_address - prints the address of a variable
 * @args: the variable to print
 * @count: pointer to count of characters printed
 */
void print_address(va_list args, format_t format, void *count)
{
    unsigned long int address = (unsigned long int)va_arg(args, void *);
    char *n = _itoa(address, HEXADECIMAL);
    format.width -= 2; /* remove 0x length */

    CHECK_RIGHT_JUSTIFICATION(n, format, count, justifier)

    _puts("0x", count);
    _puthex(address, count, 0);

    CHECK_LEFT_JUSTIFICATION(n, format, count, justifier)

    _putchar('\0', count);
    free(n);
}
