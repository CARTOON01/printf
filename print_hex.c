#include "main.h"
#include <stdlib.h>

void print_hex_helper(unsigned int number, void *count)
{
    unsigned int digit;

    if (number == 0)
        return;
    print_hex_helper(number >> 4, count);
   digit = number & 0xf;
    _putchar (digit + (digit < 10 ? '0' : 'a' - 10), count);
}

/**
 * print_hex - prints the hex representation of a number
 * @args: the number to print
 * @count: pointer to count of characters printed
 */
void print_hex(va_list args, format_t format, void *count)
{
    unsigned int number = va_arg(args, unsigned int);
    int upper = in_flags('X', format.flags) ? 1 : 0;
    char* base = upper ? "0123456789ABCDEF" : "0123456789abcdef";
    char *n = _itoa(number, base);
    char symbol = in_flags('#', format.flags) && number != 0 ? '#' : 0;

    symbol ? format.width -= 2 : 0;

    CHECK_RIGHT_JUSTIFICATION(n, format, count, justifier)

    if (symbol)
        _puts(upper ? "0X" : "0x", count);

    _puts(n, count);

    CHECK_LEFT_JUSTIFICATION(n, format, count, justifier)

    _putchar('\0', count);
    free(n);
}
