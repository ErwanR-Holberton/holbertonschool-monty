#include "main.h"
int main(int arg_count, char **arg_values)
{
	int descriptor, bytes_read = 10, i;
	FILE *stream;
	ssize_t len;
	char buffer[10], save[10], *line = NULL;

	if (arg_count != 2)
		return (0);
	stream = fopen(arg_values[1], "r");

	while (1)
	{
		if (getline(&line, &len, stream) == -1)
			break;
		printf("%s", line);
	}
	return (0);

}
