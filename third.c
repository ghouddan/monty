#include "main.h"
#define BUFSIZE 64

char *operand;

/**
 * main - Monty interpreter
 * @argc: Number of arguments
 * @argv: List of arguments
 * Return: Nothing
 */
int main(int argc, char const *argv[])
{
	line_t *Lines;
	char **lineTokens;
	int lineNumber;
	stack_t *stack;
	char *content;
	void (*func)(stack_t **, unsigned int);

	stack = NULL;

	if (argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	Lines = textfileToArray(argv[1]);
	if (Lines == NULL)
		return (0);

	lineNumber = 0;
	while ((Lines + lineNumber)->content != NULL)
	{
		content = (Lines + lineNumber)->content;
		lineTokens = split_line(content);
		operand = lineTokens[1];

		func = get_op_func(lineTokens[0]);
		if (func == NULL)
		{
			/* TODO: Refactor: Edit more efficient way to free memory on exit */
			fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber + 1, lineTokens[0]);
			free(lineTokens);
			freeStack(stack);
			freeLines(Lines);
			exit(EXIT_FAILURE);
		}

		func(&stack, lineNumber + 1);
		free(lineTokens);
		lineNumber++;
	}

	freeStack(stack);
	freeLines(Lines);
	return (0);
}
