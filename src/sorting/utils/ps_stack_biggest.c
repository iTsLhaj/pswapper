#include <stack.h>

t_stack	*ps_stack_get_biggest(t_stack *stack)
{
	t_stack	*big;

	if (stack == NULL)
		return (NULL);
	big = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > big->value)
			big = stack;
		stack = stack->next;
	}
	return (big);
}
