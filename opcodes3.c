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
/**
 * _pchar - prints the char value of the top of the stack
 * @dbly: head of the linked list
 * @count_line: line number
 * Return: void.
 */
void _pchar(stack_t **dbly, unsigned int count_line)
{
	stack_t *curr = NULL;

	curr = *dbly;
	if (curr == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", count_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if (curr->n < 0 || curr->n > 127)
	{
		dprintf(2, "L%u: ", count_line);
		dprintf(2, "can't pchar, value out of range\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*dbly)->n);
}
/**
 * _pstr - prints the string starting at the top of the stack
 * @dbly: head of the linked list
 * @count_line: line number
 * Return: void.
 */
void _pstr(stack_t **dbly, unsigned int count_line)
{
	stack_t *curr;
	(void)count_line;

	curr = *dbly;
	while (curr && curr->n > 0 && curr->n < 128)
	{
		printf("%c", curr->n);
		curr = curr->next;
	}

	printf("\n");
}

/**
 * _rotl - rotates the stack to the top
 * @dbly: head of the linked list
 * @count_line: line number
 * Return: void.
 */
void _rotl(stack_t **dbly, unsigned int count_line)
{
	int value;
	stack_t *curr;

	curr = *dbly;
	if (curr == NULL || curr->next == NULL)
		return;
	value = curr->n;
	_pop(dbly, count_line);
	add_dnodeint_end(dbly, value);
}

/**
 * _rotr - rotates the stack to the bottom
 * @dbly: head of the linked list
 * @count_line: line number
 * Return: void.
 */
void _rotr(stack_t **dbly, unsigned int count_line)
{
	stack_t *curr;
	(void)count_line;
	
	curr = *dbly;
	if (curr == NULL || curr->next == NULL)
		return;
	while (curr->next != NULL)
		curr = curr->next;
	curr->prev->next = NULL;
	curr->prev = NULL;
	curr->next = (*dbly);
	(*dbly)->prev = curr;
	*dbly = curr;
}
