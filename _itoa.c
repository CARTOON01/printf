#include <stdlib.h>   // for abs() function
#include <string.h>   // for strlen() function
#include "main.h"
#include <stdio.h>

char* _strdup(char *str)
{
    char *dup;
    int i, len = _strlen(str);

    dup = malloc(len + 1);
    if (dup == NULL)
        return (NULL);
    for (i = 0; i < len; i++)
        dup[i] = str[i];
    dup[len] = '\0';
    return (dup);
}

char* reverse_string(char *str)
{
    int i, len = _strlen(str);
    char *rev = malloc(len + 1);

    for (i = 0; i < len; i++)
        rev[i] = str[len - i - 1];
    rev[len] = '\0';
    free(str);
    return (rev);
}

char* _itoa(ssize_t value, char *base)
{
    char* result = malloc(get_number_length(value) + 1);
    char* ptr;
    unsigned int quotient;
    int base_len = _strlen(base);
    if (base_len < 2 || base_len > 16) {
        return NULL;
    }

    ptr = result;
    quotient = ABS(value);

    // convert integer to ASCII string in reverse order
    do {
        *ptr++ = base[quotient % base_len];
        quotient /= base_len;
    } while (quotient);

    // add sign for negative values
    if (value < 0 && base_len == 10) *ptr++ = '-';

    *ptr-- = '\0';
    return reverse_string(result);
}
