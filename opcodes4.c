#include "monty.h"

/**
 * _stack - sets the format of the data
 * to a stack (LIFO)
 * @dbly: head of the linked list
 * @count_line: line number
 * Return: void.
 */
void _stack(stack_t **dbly, unsigned int count_line)
{
	(void)dbly;
	(void)count_line;

	vglo.lifo = 1;
}

/**
 * _queue - sets the format of the data
 * to a queue (FIFO)
 * @dbly: head of the linked list
 * @count_line: line number
 * Return: void.
 */
void _queue(stack_t **dbly, unsigned int count_line)
{
	(void)dbly;
	(void)count_line;

	vglo.lifo = 0;
}
