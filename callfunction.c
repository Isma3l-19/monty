#include "monty.h"
/**
 * call_fun - calls the required function
 * @func: Pointer to the function that is about to be called
 * @op: string representing the opcode
 * @val: string representing a numeric value
 * @ln: line numeber for the instruction
 * @format: format specifier
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
		{
			err(5, ln);
		}
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
			{
				error(5, ln);
			}
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
		{
			func(&node, ln);
		}
		if (format == 1)
		{
			add_to_queue(&node, ln);
		}
	}
	else
	{
		func(&head, ln);
	}
}
