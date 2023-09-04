#include "main.h"
int main(int arg_count, char **arg_values)
{
	int descriptor, bytes_read = 10, i;
	char buffer[10], save[10];

	if (arg_count != 2)
		return (0);
	descriptor = open(arg_values[1], O_RDONLY);

	while (bytes_read == 10)
	{
		bytes_read = read(descriptor, buffer, 10);
		if (bytes_read < 10)
			buffer[bytes_read] = '\0';
		printf("%s", buffer);
	}

}
