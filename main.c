#include "main.h"
int main(int arg_count, char **arg_values)
{
	int line_count = 0;
	FILE *stream;
	size_t len;
	char *line = NULL;

	if (arg_count != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", arg_values[0]);
		return (0);
	}
	stream = fopen(arg_values[1], "r");

	while (getline(&line, &len, stream) != -1)
	{
		line_count++;
		printf("%s", line);
	}

	free(line);
	fclose(stream);
	return (0);

}
