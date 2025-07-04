#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet in lowercase 10 times,
 *                     each followed by a new line
 */
void print_alphabet_x10(void)
{
    int i, j;
    char ch;

    for (i = 0; i < 10; i++)  /* Repeat 10 times */
    {
        ch = 'a';
        for (j = 0; j < 26; j++)  /* Print alphabet */
        {
            _putchar(ch);
            ch++;
        }
        _putchar('\n');
    }
}
