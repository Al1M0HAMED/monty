#include "monty.h"
/**
 * add - delets the top element of the stack.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void add(stack_t **stack, unsigned int line_number)
{
	long int n;
	stack_t *temp = *stack;

	if (stack_len(stack) < 2)
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = temp->n;
	temp = temp->next;
	n += temp->n;
	pop(stack, line_number);
	pop(stack, line_number);
	*stack = add_element(stack, n);
}
/**
 * sub - subs the top two elements of the stack.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	long int n;
	stack_t *temp = *stack;

	if (stack_len(stack) < 2)
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	n = (temp->n - (*stack)->n);
	pop(stack, line_number);
	pop(stack, line_number);
	*stack = add_element(stack, n);
}
/**
 * div_stack - divides the top two elements of the stack.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	long int n;
	stack_t *temp = *stack;

	if (stack_len(stack) < 2)
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: division by zero\n", line_number);
		exit(EXIT_FAILURE);

	}
	temp = temp->next;
	n = (temp->n / (*stack)->n);
	pop(stack, line_number);
	pop(stack, line_number);
	*stack = add_element(stack, n);
}
/**
 * mod_stack - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void mod_stack(stack_t **stack, unsigned int line_number)
{
	long int n;
	stack_t *temp = *stack;

	if (stack_len(stack) < 2)
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: division by zero\n", line_number);
		exit(EXIT_FAILURE);

	}
	temp = temp->next;
	n = (temp->n % (*stack)->n);
	pop(stack, line_number);
	pop(stack, line_number);
	*stack = add_element(stack, n);
}
/**
 * mul - divides the top two elements of the stack.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	long int n;
	stack_t *temp = *stack;

	if (stack_len(stack) < 2)
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	n = (temp->n * (*stack)->n);
	pop(stack, line_number);
	pop(stack, line_number);
	*stack = add_element(stack, n);
}
