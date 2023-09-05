#include "monty.h"
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
	unsigned int i;
	stack_t *new_element = malloc(sizeof(stack_t));

	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error = 1;
		return;
	}

	if (value_str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new_element);
		error = 1;
		return;
	}
	for (i = 0; i < strlen(value_str); i++)
		if ((value_str[i] < '0' || value_str[i] > '9') && value_str[i] != '-'
		&& value_str[i] != '+')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(new_element);
			error = 1;
			return;
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
/**
 * f_pop - remove first element of the list
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: remove first element of the list
 * Return: NOTHING
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
