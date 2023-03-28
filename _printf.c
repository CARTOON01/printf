#include "main.h"
#include <stdlib.h>
#include <ctype.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0, i;
    va_list args;

    format_specifier format_specifiers[] = {
        {"c", print_char},
        {"s", print_string},
        {"%", print_percent},
        {"d", print_integer},
        {"i", print_integer},
        {"b", print_binary},
        {"o", print_octal},
        {"x", print_hex},
        {"X", print_hex},
        {"u", print_unsigned},
        {"r", print_reverse},
        {"R", print_rot13},
        {"p", print_address},
        {"S", print_string_non_printable},
        {NULL, NULL}
    };

    format_t f = {0, -1, -1, -1, -1};

    /* todo: handle the case where format is NULL */
    if (format == NULL)
        return (-1);

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;

            f = get_format(&format);
            for (i = 0; format_specifiers[i].specifier; ++i)
                if (f.specifier == *format_specifiers[i].specifier) {
                    format_specifiers[i].function(args, f, &count);
                    break;
                }

            /* todo: handle the case where the format specifier is not found */
            if (format_specifiers[i].specifier == NULL) {
//                _putchar(*(format - 1), &count);
                _putchar(*format, &count);
                format++;
            }
            free(f.flags);
        }
        else {
            _putchar(*format, &count);
            format++;
        }
    }
    va_end(args);

    _putchar('\0', &count);

    return (count);
}
