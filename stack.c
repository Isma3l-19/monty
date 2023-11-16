#include "monty.h"
/**
 * add_to_stack - adds node to stack
 * @new_node: pointer to the new node
 * @ln: interger representing the line number of of the opcode
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}
/**
 * print_stack - adds a node to the stack
 * @stack: double pointer pointing to top node of the stack
 * @line_number: number of  the opcode
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pop_top - adds a node to the stack
 * @stack: double pointer pointing to top node of the stack
 * @line_number: int representing the line number of of the opcode
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		more_error(7, line_number);
	}
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(tmp);
}
/**
 * print_top - prints the top node of the stack
 * @stack: double pointer pointing to top node of the stack
 * @line_number: int representing the line number of of the opcode
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		more_error(6, line_number);
	}
	printf("%d\n", (*stack)->n);
}
