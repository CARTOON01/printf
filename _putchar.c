#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @count: The number of characters printed
 */
void _putchar(char c, void *count)
{
    static char buffer[BUFFER_SIZE];
    static int index = 0;

    if (c == '\0' || index == BUFFER_SIZE)
    {
        write(STDOUT_FILENO, buffer, index);
        index = 0;
    }
    buffer[index++] = c;
    if (c != '\0')
        (*(int *)count)++;
}
