#include "main.h"
#include <stdlib.h>

void print_octal_helper(unsigned int number, void *count)
{
    if (number == 0)
        return;
    print_octal_helper(number >> 3, count);
    _putchar((number & 7) + '0', count);
}

/**
 * print_octal - prints the octal representation of a number
 * @args: the number to print
 * @count: pointer to count of characters printed
 */
void print_octal(va_list args, format_t format, void *count)
{
    unsigned int number = va_arg(args, unsigned int);
    char *n = _itoa(number, OCTAL);

    CHECK_RIGHT_JUSTIFICATION(n, format, count, justifier)

    _puts(n, count);

    CHECK_LEFT_JUSTIFICATION(n, format, count, justifier)

    _putchar('\0', count);

    free(n);
}
