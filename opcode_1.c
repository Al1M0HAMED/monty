#include "monty.h"
/**
 * is_empty - checks if the stack is empty.
 * @stack: is the stack
 * Return: true if empty if not return true
 */
bool is_empty(stack_t **stack)
{
	if (*stack)
		return (false);
	return (true);
}
/**
 * stack_len - count stack elements.
 * @stack: is the stack.
 * Return: stac length.
 */
unsigned int stack_len(stack_t **stack)
{
	unsigned int len = 0;
	stack_t *temp = *stack;

	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
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
