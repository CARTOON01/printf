#include "main.h"

/**
 * print_char - prints a character
 * @args: the character to print
 * @count: pointer to count of characters printed
 */
void print_char(va_list args, format_t format, void *count)
{
    char c = va_arg(args, int);
    char character[2];
    character[0] = c;
    character[1] = 0;

    CHECK_RIGHT_JUSTIFICATION(character, format, count, justifier)

    _putchar(c, count);

    CHECK_LEFT_JUSTIFICATION(character, format, count, justifier)

    _putchar('\0', count);
}
