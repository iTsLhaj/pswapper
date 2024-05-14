#include <stack.h>

t_stack	*ps_stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	else
	{
		while (stack->next)
			stack = stack->next;
		return (stack);
	}
}
