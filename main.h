#ifndef PRINTF_MAIN_H
#define PRINTF_MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define BINARY "01"
#define OCTAL "01234567"
#define DECIMAL "0123456789"
#define HEXADECIMAL "0123456789abcdef"
#define PRINT_VAR_NAME(var) printf(#var " = %d\n", var)

#define CHECK_RIGHT_JUSTIFICATION(value, format, count, justifier_func) \
    if (!in_flags('-', format.flags)) \
        justifier_func(value, format, count);

#define CHECK_LEFT_JUSTIFICATION(value, format, count, justifier_func) \
    if (in_flags('-', format.flags)) \
        justifier_func(value, format, count);


#define BUFFER_SIZE 1024
#define ABS(x) ((x) < 0 ? -(x) : (x))

#define UNUSED(x) (void)(x)

typedef struct {
    char* flags;
    int width;
    int precision;
    int length;
    char specifier;
} format_t;

typedef struct {
    char *specifier;
    void (*function)(va_list, format_t, void *);
} format_specifier;

void print_char(va_list, format_t, void *);
void print_string(va_list, format_t, void *);
void print_percent(va_list, format_t, void *);
void print_integer(va_list, format_t, void *);
void print_binary(va_list, format_t, void *);
void print_octal(va_list, format_t, void *);
void print_hex(va_list, format_t, void *);
void print_unsigned(va_list, format_t, void *);
void print_reverse(va_list, format_t, void *);
void print_rot13(va_list, format_t, void *);
void print_address(va_list, format_t, void *);
void print_string_non_printable(va_list, format_t, void *);

int in_flags(char c, const char *flags);
format_t get_format(const char **);
int get_number_length(int);
void justifier(char *, format_t, void *);

int _printf(const char *format, ...);
void _puts(char *, void *);
void _putchar(char, void *);

int _strlen(char *s);
char* _itoa(ssize_t , char *);
char* _strdup(char *);


#endif /* PRINTF_MAIN_H */
