#include "monty.h"
/**
 * push - push element in the stack.
 * @stack: is the address of the stack.
 * @line_number: is the line number.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *endptr;
	long int n;
	char *s;

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
	if (data.is_queue)
		add_element_end(stack, n);
	else
		*stack = add_element(stack, n);
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
 * pint - prints the top element of the stack.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (is_empty(stack))
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%i\n", (*stack)->n);
	}
}
/**
 * pop - delets the top element of the stack.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (is_empty(stack))
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(temp);
}
/**
 * swap - swaps the top two elements of a stack.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int n;

	if (stack_len(stack) < 2)
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = temp->next;
		n = temp->n;
		temp->n = (*stack)->n;
		(*stack)->n = n;
	}
}
