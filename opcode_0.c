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
/**
 * add_element - adds an element to a stack.
 * @stack: is the stack.
 * @n: is the new element data.
 * Return: the address of the new element or NULL if Failed.
 */
stack_t *add_element(stack_t **stack, long int n)
{
	stack_t *new_element;

	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_element->prev = NULL;
	new_element->next = *stack;
	if (*stack)
		(*stack)->prev = new_element;
	new_element->n = n;
	return (new_element);
}
/**
 * add_element_end - adds an element to a queue.
 * @stack: is the stack.
 * @n: is the new element data.
 * Return: the address of the new element or NULL if Failed.
 */
stack_t *add_element_end(stack_t **stack, long int n)
{
	stack_t *new_element, *temp = *stack;

	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		free_stack(stack);
		fclose(data.file_ptr);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	while (temp && temp->next)
		temp = temp->next;
	new_element->next = NULL;
	new_element->prev = temp;
	if (temp)
		temp->next = new_element;
	else
		*stack = new_element;
	new_element->n = n;
	return (new_element);
}

