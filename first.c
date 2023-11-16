#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: Always 
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	char *str = NULL, *operator_array[2], *temp;
	size_t bufferSize = 1024, lineCount = 0;
	ssize_t getLine;
	void (*operator_function)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		getLine = getline(&str, &bufferSize, file);
		if (getLine == -1)
			break;
		lineCount++;
		operator[0] = strtok(str, "\n ");
		if (operator[0] == NULL)
			get_nop(&head, lineCount);
		else if (strcmp("push", operator[0]) == 0)
		{
			temp = strtok(NULL, "\n ");
			get_push(&head, lineCount, temp);
		}
		else if (operator[0] != NULL && operator[0][0] != '#')
		{
			operator_function = get_operator_function(operator[0], lineCount);

			if (operator_function == NULL && lineCount == 0)
			{
				fprintf(stderr, "L%zu: unknown instruction %s\n",
					lineCount, operator[0]), exit(EXIT_FAILURE);
			}
			operator_function(&head, lineCount);
		}
	}
	fclose(file);
	free(str);
	get_free(head);
	return (0);
}
