#include "monty.h"

/**
 * OpPush - push elements to a stack
 * @stack: Pointer to the first element in a stack
 * @LineNumber: The line within the stack
 * Return: Nothing
 */
void OpPush(stack_t **stack, unsigned int LineNumber)
{
	stack_t *NewNode;
	int value;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", LineNumber);
		exit(EXIT_FAILURE);
	}

	if (operand == NULL || _atoi(operand, &value) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", LineNumber);
		exit(EXIT_FAILURE);
	}

	NewNode = malloc(sizeof(stack_t));

	if (NewNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(*stack);
		exit(EXIT_FAILURE);
	}

	NewNode->next = *stack;
	NewNode->prev = NULL;
	NewNode->n = value;

	if (*stack)
		(*stack)->prev = NewNode;
	*stack = NewNode;
}

/**
 * OpPall - data from node to a stack
 * @stack: Pointer to the head node pointer
 * @LineNumber: The line number
 * Return: Void
 */
void OpPall(stack_t **stack, unsigned int LineNumber)
{
	stack_t *temp;
	(void)LineNumber;
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * OpPint - Prints the value at the top of the stack
 * @stack: Pointer to the head node pointer
 * @LineNumber: The line number
 * Return: Void
 */
void op_pint(stack_t **stack, unsigned int LineNumber)
{
	stack_t *temp;
	(void)LineNumber;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", LineNumber);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	printf("%d\n", temp->n);
}

