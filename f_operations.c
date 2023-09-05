#include "monty.h"
/**
 * f_add - add the top two elements of the list
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: add the top two elements of the list
 * Return: NOTHING
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		error = 1;
		return;
	}
	(*stack)->next->n += (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}
/**
 * f_sub - subtracts the first element from the second of the list
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: subtracts the first element from the second of the list
 * Return: NOTHING
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		error = 1;
		return;
	}
	(*stack)->next->n = (*stack)->n - (*stack)->next->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}
