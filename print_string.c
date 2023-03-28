#include "main.h"

/**
 * print_string - prints a string
 * @args: the string to print
 * @count: pointer to count of characters printed
 */
void print_string(va_list args, format_t format, void *count)
{
    char *str = va_arg(args, char *);

    CHECK_RIGHT_JUSTIFICATION(str, format, count, justifier)

    _puts(str, count);

    CHECK_LEFT_JUSTIFICATION(str, format, count, justifier)
    _putchar('\0', count);
}
