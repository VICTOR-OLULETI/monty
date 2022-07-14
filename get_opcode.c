#include "monty.h"
/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: ponter to the function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int count_line)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}
