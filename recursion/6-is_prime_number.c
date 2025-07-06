#include "main.h"

/**
 * _is_prime_helper - Checks if n is divisible by a divisor
 * @n: Number to check
 * @divisor: Current divisor to test
 *
 * Return: 1 if prime, 0 if not
 */
int _is_prime_helper(int n, int divisor)
{
	if (n <= 1)
		return (0);

	if (divisor * divisor > n)
		return (1);

	if (n % divisor == 0)
		return (0);

	return (_is_prime_helper(n, divisor + 1));
}

/**
 * is_prime_number - Returns 1 if n is prime, else 0
 * @n: Number to check
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	return (_is_prime_helper(n, 2));
}
