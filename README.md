# printf
This repo contains an ALX-Group project that involved recreation of the printf function of the standard library.

The __printf function is used to print all data types (which are passed as arguments) when the program is compiled. 
Formating options are used to print the various data types. For example:
* %d prints a decimal number
* %i prints an integer
* %c prints a character
* %s prints a string

In order to use this function, the prototype declaration should be:

* int _printf(const char *format, ...);

The function can be called as follows:

* _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);

The output of the function call will be: