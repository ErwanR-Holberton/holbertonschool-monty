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
	(*stack)->next->n -= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}
/**
 * f_div - divides the second top element by the top element of the stack
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: divides the second top element by the top element of the stack
 * Return: NOTHING
 */
void f_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		error = 1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		error = 1;
		return;
	}
	(*stack)->next->n /= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}
/**
 * f_mun - multiplies the second top two elements of the stack
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: multiplies the second top two elements of the stack
 * Return: NOTHING
 */
void f_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		error = 1;
		return;
	}
	(*stack)->next->n *= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}
/**
 * f_mod - element 2 becomes the rest of E2/E1 and element 1 is freed
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: element 2 becomes the rest of E2/E1 and element 1 is freed
 * Return: NOTHING
 */
void f_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		error = 1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		error = 1;
		return;
	}
	(*stack)->next->n %= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}
