#include "monty.h"
/**
 * find_function_to_call - searches for the command in the array
 * @line: one command line of the .m file
 * @array: array with a function for each command/ instruction
 * @line_count: number of the current command line
 *
 * Description: searches for the command in the array
 * Return: the index of the correpoding function
 */
int find_function_to_call(char *line, instruction_t array[], int line_count)
{
	char *instruction = strtok(line, " \n");
	int i;

	if (instruction == NULL)
		return (-2);
	for (i = 0; array[i].opcode != NULL; i++)
		if (strcmp(instruction, array[i].opcode) == 0)
			return (i);

	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, instruction);
	return (-1);
}
/**
 * free_stack - frees the whole stack
 * @stack: the list of values used during the program
 *
 * Description: frees the whole stack
 * Return: NOTHING
 */
void free_stack(stack_t **stack)
{
	stack_t *next_stack;

	while (*stack != NULL)
	{
		next_stack = (*stack)->next;
		free(*stack);
		*stack = next_stack;
	}
}
