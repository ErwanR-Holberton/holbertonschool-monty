#include "main.h"
void f_push()
{
	char *value_str = strtok(NULL, " \n");

	printf("called push\n");
	printf("%s\n", value_str);
}
void f_pall()
{
	printf("called pall\n");
}
