#include "monty.h"

/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element
 * @dbly: head of linked list
 * @count_line: line number
 * Return: void.
 */
void _mod(stack_t **dbly, unsigned int count_line)
{
	int i = 0;
	stack_t *curr = NULL;

	curr = *dbly;
	for (; curr != NULL; curr = curr->next, i++)
		;
	if (i < 2)
	{
		dprintf(2, "L%u: ", count_line);
		dprintf(2, "can't mod, stack too short\n");
		exit(EXIT_FAILURE);
	}
	if ((*dbly)->n == 0)
	{
		dprintf(2, "L%u: ", count_line);
		dprintf(2, "division by zero\n");
		exit(EXIT_FAILURE);
	}
	curr = (*dbly)->next;
	curr->n %= (*dbly)->n;
	_pop(dbly, count_line);
}
