#include <stack.h>

t_stack	*ps_stack_get_smallest(t_stack *stack)
{
	t_stack	*smol;

	if (stack == NULL)
		return (NULL);
	smol = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < smol->value)
			smol = stack;
		stack = stack->next;
	}
	return (smol);
}
