#include "monty.h"
/**
 * find_function - searches for the command in the array
 * @line: one command line of the .m file
 * @array: array with a function for each command/ instruction
 * @line_count: number of the current command line
 * @mode: queue 1 or stack 0
 *
 * Description: searches for the command in the array
 * Return: the index of the correpoding function
 * or -1 on failure (no command with this name)
 * -2 on empty line
 * -3 on comments (do nothing)
 */
int find_function(char *line, instruction_t array[], int line_count, int *mode)
{
	char *instruction = strtok(line, " \n");
	int i;

	if (instruction == NULL)/*nothing on the line*/
		return (-2);/* -2 error will not stop the program*/
	if (instruction[0] == '#')/*comments*/
		return (-3);
	if (strcmp(instruction, "queue") == 0 && *mode == 0)
	{
		*mode = 1;
		return (-4);
	}
	if (strcmp(instruction, "stack") == 0 && *mode == 1)
	{
		*mode = 0;
		return (-4);
	}
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
