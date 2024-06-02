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
 * nop - nothing.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{

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
