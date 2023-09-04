#include "main.h"
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
	instruction_t array_string_function[] = {{"push", f_push}, {"pall", f_pall}};

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
		array_string_function[f].f(&list_head, line_count);
	}

	free(line);
	fclose(stream);
	return (0);

}
