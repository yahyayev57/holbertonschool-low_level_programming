#include <stdio.h>

/**
 * main - prints all single digit numbers separated by comma and space
 *
 * Return: Always 0
 */
int main(void)
{
    int i;

    for (i = 0; i <= 9; i++)
    {
        putchar(i + '0');        // print digit
        if (i != 9)
        {
            putchar(',');        // print comma
            putchar(' ');        // print space
        }
    }
    putchar('\n');              // print newline

    return (0);
}
