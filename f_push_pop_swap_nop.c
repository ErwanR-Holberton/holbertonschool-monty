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
 * f_pop - remove first element of the list
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: remove first element of the list
 * Return: NOTHING
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *save = *stack;

	(void)line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		error = 1;
		return;
	}
	*stack = (*stack)->next;
	free(save);
	if (*stack != NULL)
		(*stack)->prev = NULL;
}
/**
 * f_swap - swap the top two elements of the list
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: swap the top two elements of the list
 * Return: NOTHING
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	int save;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		error = 1;
		return;
	}
	save = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = save;
}
/**
 * f_nop - doesn’t do anything.
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: doesn’t do anything.
 * Return: NOTHING
 */
void f_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * f_push_queue - add a node at the end of the list
 * @stack: points to the start of a list
 * @line_number: number of the current command line
 *
 * Description: add a node at the end of the list
 * Return: NOTHING
 */
void f_push_queue(stack_t **stack, unsigned int line_number)
{
	char *value_str = strtok(NULL, " \n");
	unsigned int i;
	stack_t *new_element = malloc(sizeof(stack_t)), *current = *stack;

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
	new_element->next = NULL;

	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		new_element->prev = current;
		current->next = new_element;
	}
	else
	{
		*stack = new_element;
		new_element->prev = NULL;
	}
}
