#include "main.h"

/**
 * print_string_non_printable - prints a string in non-printable format
 * @args: the string to print
 * @count: pointer to count of characters printed
 */
void print_string_non_printable(va_list args, format_t format, void *count)
{
    char *str = va_arg(args, char *);
    int i;
    (void)format; // todo: remove this

    CHECK_RIGHT_JUSTIFICATION(str, format, count, justifier)

    for (i = 0; str[i]; i++)
    {
        if (str[i] < 32 || str[i] >= 127)
        {
            _puts("\\x", count);
            _putchar((str[i] / 16) + '0', count);
            _putchar((str[i] % 16) + '0', count);
        }
        else
            _putchar(str[i], count);
    }

    CHECK_LEFT_JUSTIFICATION(str, format, count, justifier)

    _putchar('\0', count);
}
