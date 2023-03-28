#include "main.h"

int get_number_length(int n)
{
    int i = 0;
    if (n == 0)
        return (1);
    if (n < 0) {
        n *= -1;
        i++; // todo: check if this is needed
    }
    while (n) {
        n /= 10;
        i++;
    }
    return (i);
}

/**
 * justifier - justifies a string
 * @n: number of spaces to justify
 * @count: pointer to count of characters printed
 */
void justifier(char* n, format_t format, void *count)
{
    int number_length = _strlen(n);
    char c = in_flags('0', format.flags) && !in_flags('-', format.flags) ? '0' : ' ';

    for (; format.width - number_length > 0; format.width--)
        _putchar(c, count);
}
