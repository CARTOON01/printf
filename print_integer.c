#include "main.h"
#include "stdlib.h"

/**
 * print_integer - prints an integer
 * @args: the integer to print
 * @count: pointer to count of characters printed
 */
void print_integer(va_list args, format_t format, void *count)
{
    int number = va_arg(args, int);
    char sign = in_flags('+', format.flags) && number >= 0? '+' : 0;
    char *n = _itoa(number, "0123456789");

    sign != 0 ? format.width-- : 0;

    if (!in_flags('-', format.flags))
        justifier(n, format, count);

    CHECK_RIGHT_JUSTIFICATION(n, format, count, justifier)

    _putchar(sign, count);
    _puts(n, count);

    CHECK_LEFT_JUSTIFICATION(n, format, count, justifier)

    _putchar('\0', count);
    free(n);
}
