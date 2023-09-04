#include "main.h"
int find_function_to_call(char *line, instruction_t array[], int line_count)
{
	char *instruction = strtok(line, " \n");
	int i;

	for (i = 0; i < 2; i++)
		if (strcmp(instruction, array[i].opcode) == 0)
			return (i);

	fprintf(stderr, "L%d: unknown instruction %s\n",line_count, instruction);
	exit(EXIT_FAILURE);
}
