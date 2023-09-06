#include "monty.h"

int error = 0;

/**
 * main - interpretor for monty code
 * @arg_count: number of words the user enterred
 * @arg_values: strigs containing the different word of the command line
 *
 * Description: Reads each line 1 by 1 from a monty file
 * and execute the commands
 * Return: 0 on success, 1 on failure
 */
int main(int arg_count, char **arg_values)
{
	int line_count = 0, f;
	FILE *stream;
	size_t len;
	char *line = NULL;
	stack_t *list_head = NULL;
	instruction_t array_string_function[] = {{"push", f_push}, {"pall", f_pall},
	{"pint", f_pint}, {"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
	{"nop", f_nop}, {"sub", f_sub}, {"div", f_div}, {"mul", f_mul},
	{"mod", f_mod}, {"pchar", f_pchar}, {"pstr", f_pstr}, {NULL, NULL}};

	if (arg_count != 2)
	{/*handle error if the user don't use format "program_name file_name"*/
		fprintf(stderr, "Usage: %s <file>\n", arg_values[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(arg_values[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg_values[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, stream) != -1)/*main loop*/
	{
		line_count++;
		f = find_function_to_call(line, array_string_function, line_count);
		if (f >= 0)
			array_string_function[f].f(&list_head, line_count);
		if (error == 1 || f == -1)
		{
			free_stack(&list_head);
			free(line);
			fclose(stream);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(&list_head);
	free(line);
	fclose(stream);
	return (0);
}
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
