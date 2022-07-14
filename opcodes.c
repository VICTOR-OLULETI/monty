#include "monty.h"
#include <string.h>

/**
 * _push - pushes element to the stack
 *
 * @dbly: head of a double linked list
 * @cline: line number
 * Return: no return
 */
void _push(stack_t **dbly, unsigned int cline)
{
	int n, j;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(dbly, n);
	else
		add_dnodeint_end(dbly, n);
}

/**
 * _pall - prints all element from top of stack
 * @dbly: head of double linked list
 * @cline: line number
 * Return: void.
 */
void _pall(stack_t **dbly, unsigned int count_line)
{
	stack_t *temp;
	(void)count_line;

	temp = *dbly;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}