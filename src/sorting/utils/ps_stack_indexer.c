#include <stack.h>


void	ps_stack_set_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}