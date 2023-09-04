#include "main.h"
/**
 * f_push - add a node to the list
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: add a node to the list
 * Return: NOTHING
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	char *value_str = strtok(NULL, " \n");
	stack_t *new_element = malloc(sizeof(stack_t));

	(void)line_number;
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_element->n = atoi(value_str);
	new_element->prev = NULL;
	new_element->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_element;
	*stack = new_element;
}
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
