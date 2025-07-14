#include "3-calc.h"

/**
 * get_op_func - Selects the correct function based on the operator
 * @s: operator passed as argument
 *
 * Return: pointer to function matching operator or NULL if no match
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if (s && s[0] == ops[i].op[0] && s[1] == '\0')
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
