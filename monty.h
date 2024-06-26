#ifndef MONTY_H
#define MONTY_H

#define BUFFER_MAX 1024

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_data_s - monty data.
 * @command: is the command str.
 * @buffer: is the buffer.
 * @stack: is the stack.
 * @file_ptr: is a file pointer to the monty file.
 * @is_queue: is detecting if code for stack or queue.
 */
typedef struct monty_data_s
{
	char buffer[BUFFER_MAX];
	char *command;
	stack_t *stack;
	FILE *file_ptr;
	bool is_queue;
} monty_data_t;
extern monty_data_t data;

void free_stack(stack_t **stack);
void handle_instructions(monty_data_t *buffer, unsigned int n);
void push(stack_t **stack, unsigned int n);
void pall(stack_t **stack, unsigned int n);
bool is_empty(stack_t **stack);
unsigned int stack_len(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_stack(stack_t **stack, unsigned int line_number);
void mod_stack(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number);
stack_t *add_element(stack_t **stack, long int n);
stack_t *add_element_end(stack_t **stack, long int n);

#endif
