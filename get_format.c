#include "main.h"
#include <stdlib.h>

int in_flags(char c, const char *flags)
{
    int i;
    for (i = 0; i < 5; i++)
        if (c == flags[i])
            return (1);
    return (0);
}

char* get_flag(const char **s)
{
    char flags[] = {'-', '+', ' ', '#', '0'};
    int i, j = 0;
    char *flag = malloc(5);

    for (i = 0; i < 5; i++) {
        if (in_flags(*(*s), flags)) {
            flag[j++] = *(*s);
            (*s)++;
        }
    }
    flag[j] = '\0';
    return (flag);
}

int get_width(const char **s)
{
    char p[1024];
    int i = 0;
    for (; *(*s) >= '0' && *(*s) <= '9'; (*s)++, i++)
        p[i] = *(*s);
    p[i] = '\0';
    return (atoi(p)); // todo: remove this.
}

int get_precision(const char **s)
{
    char p[1024] = "-1";
    int i = 0;
    *(*s) == '.' ? (*s)++ : 0;
    for (; *(*s) >= '0' && *(*s) <= '9'; (*s)++, i++)
        p[i] = *(*s);
    i ? p[i] = '\0' : 0;
    return (atoi(p)); // todo: remove this.
}

int get_length(const char **s)
{
    char length[] = {'h', 'l', 'L'};
    int i;
    char l = -1;

    for (i = 0; i < 3; i++)
        if (*(*s) == length[i])
        {
            l = length[i];
            (*s)++;
            break;
        }
    return (l);
}

char get_specifier(const char **s)
{
    char specifiers[] = {'c', 's', '%', 'd', 'i', 'b', 'o', 'x', 'X', 'u', 'r', 'R', 'p', 'S'};
    int i;
    char specifier = -1;

    for (i = 0; i < 14; i++)
        if (*(*s) == specifiers[i])
        {
            specifier = specifiers[i];
            (*s)++;
            break;
        }
    return (specifier);
}

/**
 * get_format - gets the format of the string
 * @s: the string to get the format from
 * Return: a format_t struct
 */
format_t get_format(const char **s)
{
    format_t f = {0, -1, -1, -1, -1};

    f.flags = get_flag(s);
    f.width = get_width(s);
    f.precision = get_precision(s);
    f.length = get_length(s);
    f.specifier = get_specifier(s);

    return (f);
}
