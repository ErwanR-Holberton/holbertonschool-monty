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
 *
 * Description: print the value at the top of the stack
 * Return: NOTHING
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
/**
 * f_pchar - print the value at the top of the stack as a char
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 *
 * Description: print the value at the top of the stack as a char
 * Return: NOTHING
 */
void f_pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		error = 1;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		error = 1;
		return;
	}

	printf("%c\n", (*stack)->n);
}
/**
 * f_pstr - prints the string starting at the top of the stack, and a new line
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 *
 * Description: prints the string at the top of the stack and a new line
 * Return: NOTHING
 */
void f_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	if (*stack != NULL)
		printf("\n");
}
