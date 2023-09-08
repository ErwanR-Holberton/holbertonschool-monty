#include "monty.h"
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
	int line_count = 0, f, mode = 0;/*line_count = count number of lines read*/
	FILE *stream;/* f is index of function, mode is 0 for stack 1 for queue*/
	size_t len;
	char *line = NULL;
	stack_t *list_head = NULL;
	instruction_t array_string_function[] = {{"push", f_push}, {"pall", f_pall},
	{"pint", f_pint}, {"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
	{"nop", f_nop}, {"sub", f_sub}, {"div", f_div}, {"mul", f_mul},
	{"mod", f_mod}, {"pchar", f_pchar}, {"pstr", f_pstr}, {"rotl", f_rotl},
	{"rotr", f_rotr}, {NULL, NULL}};

	if (arg_count != 2)
	{/*handle error if the user don't use format "program_name file_name"*/
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(arg_values[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg_values[1]);
		exit(EXIT_FAILURE);
	}
	error = 0;
	while (getline(&line, &len, stream) != -1 && error == 0 && f != -1)
	{/*						 main loop*/
		line_count++;
		f = find_function(line, array_string_function, line_count, &mode);
		if (f == 0 && mode == 1)
		{ f = -5; /*-5 means push has been called in queue mode*/
			f_push_queue(&list_head, line_count);
		}
		if (f >= 0)
			array_string_function[f].f(&list_head, line_count);
	}
	free_stack(&list_head);
	free(line);
	fclose(stream);
	if (error == 1 || f == -1)
		exit(EXIT_FAILURE);
	return (0);
}
