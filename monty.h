#ifndef MONTY_H
#define MONTY_H

#define BUFFER_MAX 1024

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
 * monty_data_s - monty data.
 * @buffer: is the buffer.
 * @stack: is the stack.
 * @file_ptr: is a file pointer to the monty file.
 */
typedef struct monty_data_s
{
    char buffer[BUFFER_MAX];
    stack_t *stack;
    FILE *file_ptr;
} monty_data_t;
extern monty_data_t data;

/**
 * struct list_s - singly linked list
 * @str: string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

void free_stack(stack_t **stack);
size_t print_list(const list_t *h);
list_t *add_node_end(list_t **head, char *str);
void free_list(list_t *head);
void handle_instructions(monty_data_t *buffer, unsigned int n);
void push(stack_t **stack, unsigned int n);
void pall(stack_t **stack, unsigned int n);

#endif
