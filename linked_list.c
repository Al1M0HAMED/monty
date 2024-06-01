#include "monty.h"
/**
 * add_node_end - add node to a list.
 * @head: a pointer to the head of the list.
 * @str: is a pointer to const char.
 * Return: pointer t new node.
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new_node, *temp;
	int i = 0;

	temp = *head;
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);


	while (str[i] != '\0')
	{
		new_node->str[i] = str[i];
		i++;
	}
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while ((temp)->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;

	return (new_node);
}

/**
 * print_list - printf a linked list.
 * @h: linked list.
 * Return: the length of a linked list.
 */
size_t print_list(const list_t *h)
{
	int length;

	length = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("%s\n", h->str);
		h = h->next;
		length++;
	}
	return (length);
}
/**
 * free_list - this function frees list_t list.
 * @head: is a list.
 */
void free_list(list_t *head)
{
	list_t *temp;

	temp = head;
	while (head != NULL)
	{
		temp = temp->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
