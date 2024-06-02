#include "monty.h"
/**
 * push - push element in the stack.
 * @stack: is the address of the stack.
 * @line_number: is the line number.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_element;
	char *endptr;
	long int n;
	char *s;

	if (data.buffer[0] == '\n' || data.buffer[0] == '\0')
		return;
	s = strtok(NULL, " \n\t");
	if (s == NULL)
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = strtoll(s, &endptr, 10);
	if (*endptr != '\0')
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		fclose(data.file_ptr);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_element->prev = NULL;
	new_element->next = *stack;
	if (*stack)
		(*stack)->prev = new_element;
	new_element->n = n;
	*stack = new_element;
}
/**
 * pall - prints all elements of the stack.
 * @stack: is the address of the stack.
 * @line_number: is the line number.
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}
/**
 * free_stack - this function frees a stack.
 * @stack: is the stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
