#include "monty.h"

/**
 * f_pint - print the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		error = 1;
		return;
	}

	printf("%d\n", (*stack)->n);
}
