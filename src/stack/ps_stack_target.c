#include <stack.h>


static void	ps_assign_target(t_stack *stack_a, t_stack *node)
{
	t_stack	*smallest;
	t_stack	*biggest;
	t_stack	*closest;

	smallest = ps_stack_get_smallest(stack_a);
	biggest = ps_stack_get_biggest(stack_a);
	if (node->value > biggest->value)
		node->target = smallest;
	else if (node->value < smallest->value)
		node->target = biggest;
	else
	{
		closest = NULL;
		stack_a = stack_a->next;
		while (stack_a)
		{
			if (stack_a->value > node->value)
			{
				if (closest == NULL)
					closest = stack_a;
				else if (closest->value > stack_a->value)
					closest = stack_a;
			}
			stack_a = stack_a->next;
		}
		node->target = closest;
	}
}

void	ps_stack_assign_targets(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b)
	{
		ps_assign_target(stack_a, stack_b);
		stack_b = stack_b->next;
	}
}
