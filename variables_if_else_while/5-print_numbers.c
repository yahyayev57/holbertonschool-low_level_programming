#include <stdio.h>

/**
 * main - prints digits from 0 to 9 followed by a new line
 *
 * Return: Always 0
 */
int main(void)
{
    char digit;

    for (digit = '0'; digit <= '9'; digit++)
        putchar(digit);
    putchar('\n');

    return (0);
}
