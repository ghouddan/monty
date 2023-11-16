#include "main.h"

/**
 * freeStack - Frees a stack_t list
 * @head: Head of the linked list
 */
void freeStack(stack_t *head)
{
	stack_t *current;
	stack_t *next;

	current = head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * freeLines - Frees a line_t list
 * @lines: Pointer to the line_t list
 */
void freeLines(line_t *lines)
{
	int i = 0;

	while ((lines + i)->content != NULL)
	{
		free((lines + i)->content);
		i++;
	}
	free(lines);
}
