#include "monty.h"
/**
 * f_rotl - rotates the list to the left
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: rotates the list to the left
 * meaning we put the first element a the end of the list
 * Return: NOTHING
 */
void f_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack, *current = *stack;

	(void)line_number;
	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	while (current->next != NULL)
		current = current->next;

	current->next = copy;
	copy->next = NULL;
	copy->prev = current;
}
/**
 * f_rotr - rotates the list to the right
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: rotates the list to the right
 * meaning we put the last element a the start of the list
 * Return: NOTHING
 */
void f_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;

	while (current->next != NULL)
		current = current->next;

	current->prev->next = NULL;
	current->next = *stack;
	current->prev = NULL;
	*stack = current;
}
