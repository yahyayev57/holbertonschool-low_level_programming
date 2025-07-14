#include "3-calc.h"

/**
 * op_add - Returns the sum of a and b
 * @a: int operand
 * @b: int operand
 *
 * Return: sum
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Returns the difference of a and b
 * @a: int operand
 * @b: int operand
 *
 * Return: difference
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Returns the product of a and b
 * @a: int operand
 * @b: int operand
 *
 * Return: product
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Returns the result of division of a by b
 * @a: int operand
 * @b: int operand
 *
 * Return: quotient
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - Returns the remainder of the division of a by b
 * @a: int operand
 * @b: int operand
 *
 * Return: remainder
 */
int op_mod(int a, int b)
{
	return (a % b);
}
