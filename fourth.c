#include "main.h"

/**
 * getOpFunc - function selected bu the user
 * @str: Operator argument
 *
 * Return:
 */
void (*getOpFunc(char *str))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL && strcmp(ops[i].opcode, str))
		i++;
	return ops[i].f;
}
