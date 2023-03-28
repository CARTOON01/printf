#include "main.h"
#include <stdlib.h>

void print_binary_helper(unsigned int number, void *count)
{
    if (number == 0)
        return;
    print_binary_helper(number >> 1, count);
    _putchar((number & 1) + '0', count);
}

/**
 * print_binary - prints the binary representation of a number
 * @args: the number to print
 * @count: pointer to count of characters printed
 */
void print_binary(va_list args, format_t format, void *count)
{
    unsigned int number = va_arg(args, unsigned int);
    char *n = _itoa(number, BINARY);

    CHECK_RIGHT_JUSTIFICATION(n, format, count, justifier)

    _puts(n, count);

    CHECK_LEFT_JUSTIFICATION(n, format, count, justifier)

    _putchar('\0', count);
    free(n);
}
