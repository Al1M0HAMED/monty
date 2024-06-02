#include "monty.h"
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
 * pchar - prints valid char from stack top.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (is_empty(stack))
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr - prints a valid string starting from stack top.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp && (temp->n >= 0 && temp->n <= 127) && temp->n != 0)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
/**
 * rotl - rotates the stack to the top.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int n = (*stack)->n;

	if (stack_len(stack) > 1)
	{
		pop(stack, line_number);
		add_element_end(stack, n);
	}
}
/**
 * rotr - rotates the stack to the bottom.
 * @stack: is the stack.
 * @line_number: is the line number.
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp_0 = *stack, *temp_1;
	int n;

	if (stack_len(stack) > 1)
	{
		while (temp_0 && temp_0->next)
			temp_0 = temp_0->next;
		temp_1 = temp_0->prev;
		n = temp_0->n;
		free(temp_0);
		temp_1->next = NULL;
		add_element(stack, n);
	}
}

