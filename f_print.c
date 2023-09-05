#include "monty.h"

/**
 * f_pall - print the list
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: print the list
 * Return: NOTHING
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
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
