#include <limits.h>
#include <stdio.h>
#include "main.h"

void printf_test_general(void);
void printf_test_int(void);
void printf_test_hex(void);
void printf_test_address(void);


/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    printf_test_address();
    return (0);
}

void printf_test_general(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
}

void printf_integer(void)
{
//    char c = 'a';
//    int c = 0;
    printf("Test 0: [%+5d]\n", INT_MIN);
    _printf("Test 0: [%+5d]\n", INT_MIN);

    // %d format tests
    printf("Test 1: [%d]\n", 0);
    _printf("Test 1: [%d]\n", 0);
    printf("Test 2: [%d]\n", 1);
    _printf("Test 2: [%d]\n", 1);
    printf("Test 3: [%d]\n", -1);
    _printf("Test 3: [%d]\n", -1);
    printf("Test 4: [%d]\n", INT_MIN);
    _printf("Test 4: [%d]\n", INT_MIN);
    printf("Test 5: [%d]\n", INT_MAX);
    _printf("Test 5: [%d]\n", INT_MAX);

    // %d flags tests
    printf("Test 7: [%+d]\n", 0);
    _printf("Test 7: [%+d]\n", 0);
    printf("Test 8: [%+d]\n", 1);
    _printf("Test 8: [%+d]\n", 1);
    printf("Test 9: [%+d]\n", -1);
    _printf("Test 9: [%+d]\n", -1);
    printf("Test 10: [%+d]\n", INT_MIN);
    _printf("Test 10: [%+d]\n", INT_MIN);
    printf("Test 11: [%+d]\n", INT_MAX);
    _printf("Test 11: [%+d]\n", INT_MAX);

    // %d width tests
    printf("Test 12: [%5d]\n", 0);
    _printf("Test 12: [%5d]\n", 0);
    printf("Test 13: [%5d]\n", 1);
    _printf("Test 13: [%5d]\n", 1);
    printf("Test 14: [%5d]\n", -1);
    _printf("Test 14: [%5d]\n", -1);

    // %d flags and width tests
    printf("Test 15: [%+5d]\n", 0);
    _printf("Test 15: [%+5d]\n", 0);
    printf("Test 16: [%+5d]\n", 1);
    _printf("Test 16: [%+5d]\n", 1);
    printf("Test 17: [%+5d]\n", -1);
    _printf("Test 17: [%+5d]\n", -1);
    printf("Test 18: [%+5d]\n", INT_MIN);
    _printf("Test 18: [%+5d]\n", INT_MIN);
    printf("Test 19: [%+5d]\n", INT_MAX);
    _printf("Test 19: [%+5d]\n", INT_MAX);
    printf("Test 20: [%+5d]\n", 2147483647);
    _printf("Test 20: [%+5d]\n", 2147483647);

    // %d justificator tests
    printf("Test 21: [%-5d]\n", 0);
    _printf("Test 21: [%-5d]\n", 0);
    printf("Test 22: [%-5d]\n", 1);
    _printf("Test 22: [%-5d]\n", 1);
    printf("Test 23: [%-5d]\n", -1);
    _printf("Test 23: [%-5d]\n", -1);
    printf("Test 24: [%-5d]\n", INT_MIN);
    _printf("Test 24: [%-5d]\n", INT_MIN);
    printf("Test 25: [%-5d]\n", INT_MAX);
    _printf("Test 25: [%-5d]\n", INT_MAX);
    printf("Test 26: [%-5d]\n", 2147483647);
    _printf("Test 26: [%-5d]\n", 2147483647);

    // %d flags, width and justificator tests
    printf("Test 27: [%+-5d]\n", 0);
    _printf("Test 27: [%+-5d]\n", 0);
    printf("Test 28: [%+-5d]\n", 1);
    _printf("Test 28: [%+-5d]\n", 1);
    printf("Test 29: [%+-5d]\n", -1);
    _printf("Test 29: [%+-5d]\n", -1);
    printf("Test 30: [%+-5d]\n", INT_MIN);
    _printf("Test 30: [%+-5d]\n", INT_MIN);

    // %d fill with zeros tests and flags and justificator tests
    printf("Test 31: [%0-5d]\n", 0);
    _printf("Test 31: [%0-5d]\n", 0);
    printf("Test 32: [%0-5d]\n", 1);
    _printf("Test 32: [%0-5d]\n", 1);
    printf("Test 33: [%0-5d]\n", -1);
    _printf("Test 33: [%0-5d]\n", -1);
    printf("Test 34: [%0-5d]\n", INT_MIN);
    _printf("Test 34: [%0-5d]\n", INT_MIN);

}

void printf_test_hex(void)
{
    _printf("Test 1: [%x]\n", 0);
    printf("Test 1: [%x]\n", 0);
    _printf("Test 2: [%x]\n", 1);
    printf("Test 2: [%x]\n", 1);
    _printf("Test 3: [%x]\n", -1);
    printf("Test 3: [%x]\n", -1);
    _printf("Test 4: [%x]\n", INT_MIN);
    printf("Test 4: [%x]\n", INT_MIN);

    // test #
    _printf("Test 5: [%#x]\n", 0);
    printf("Test 5: [%#x]\n", 0);
    _printf("Test 6: [%#x]\n", 1);
    printf("Test 6: [%#x]\n", 1);
    _printf("Test 7: [%#x]\n", -1);
    printf("Test 7: [%#x]\n", -1);
    _printf("Test 8: [%#x]\n", INT_MAX);
    printf("Test 8: [%#x]\n", INT_MAX);
    _printf("Test 9: [%#x]\n", INT_MIN);
    printf("Test 9: [%#x]\n", INT_MIN);


    printf("----\n");
    printf("Test 10: [%10x]\n", 0);
    _printf("Test 7: [%10x]\n", 0);
    printf("Test 11: [%10x]\n", 1);
    _printf("Test 8: [%10x]\n", 1);
    printf("Test 12: [%10x]\n", -1);
    _printf("Test 9: [%10x]\n", -1);
    printf("Test 13: [%10x]\n", INT_MIN);
    _printf("Test 10: [%10x]\n", INT_MIN);
    printf("Test 14: [%10x]\n", INT_MAX);
    _printf("Test 11: [%10x]\n", INT_MAX);

    printf("Test 10: [%-10x]\n", 0);
    _printf("Test 7: [%-10x]\n", 0);
    printf("Test 11: [%-10x]\n", 1);
    _printf("Test 8: [%-10x]\n", 1);
    printf("Test 12: [%-10x]\n", -1);
    _printf("Test 9: [%-10x]\n", -1);
    printf("Test 13: [%-10x]\n", INT_MIN);
    _printf("Test 10: [%-10x]\n", INT_MIN);
    printf("Test 14: [%-10x]\n", INT_MAX);
    _printf("Test 11: [%-10x]\n", INT_MAX);

}

void printf_test_address(void)
{
    void *c = "";

    printf("Test 1: [%p]\n", c);
    _printf("Test 1: [%p]\n", c);
    printf("Test 2: [%4p]\n", NULL);
    _printf("Test 2: [%4p]\n", NULL);

}
