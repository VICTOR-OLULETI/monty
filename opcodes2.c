#include "monty.h"

/**
 * _add - adds the top 2 elements on the stack
 * @dbly: head of the linked list
 * @count_line: line number
 * Return: void.
 */
void _add(stack_t **dbly, unsigned int count_line)
{
	int i = 0;
	stack_t *curr = NULL;

	curr = *dbly;
	for (; curr != NULL; curr = curr->next, i++)
		;
	if (i < 2)
	{
		dprintf(2, "L%u: ", count_line);
		dprintf(2, "can't add, stack too short\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	curr = (*dbly)->next;
	curr->n += (*dbly)->n;
	_pop(dbly, count_line);
}
