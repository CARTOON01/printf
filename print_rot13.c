#include "main.h"

/**
 * print_rot13 - prints a string in rot13
 * @args: the string to print
 * @count: pointer to count of characters printed
 */
void print_rot13(va_list args, format_t format, void *count)
{
    char *str = va_arg(args, char *);
    int i = 0;

    CHECK_RIGHT_JUSTIFICATION(str, format, count, justifier)

    while (str[i])
    {
        if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
            _putchar(str[i] + 13, count);
        else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
            _putchar(str[i] - 13, count);
        else
            _putchar(str[i], count);
        i++;
    }

    CHECK_LEFT_JUSTIFICATION(str, format, count, justifier)

    _putchar('\0', count);
}
