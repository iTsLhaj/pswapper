#include <stack.h>

/// Closest Smaller
static void	ps_assign_target_cs(t_stack *stack, t_stack *node)
{
	t_stack	*smallest;
	t_stack	*biggest;
	t_stack	*closest;

	smallest = ps_stack_get_smallest(stack);
	biggest = ps_stack_get_biggest(stack);
	if (node->value > biggest->value)
		node->target = smallest;
	else if (node->value < smallest->value)
		node->target = biggest;
	else
	{
		closest = NULL;
		while (stack)
		{
			if (stack->value > node->value)
			{
				if (closest == NULL)
					closest = stack;
				else if (closest->value > stack->value)
					closest = stack;
			}
			stack = stack->next;
		}
		node->target = closest;
	}
}

/// Closest Bigger
static void	ps_assign_target_cb(t_stack *stack, t_stack *node)
{
	t_stack	*smallest;
	t_stack	*biggest;
	t_stack	*closest;

	smallest = ps_stack_get_smallest(stack);
	biggest = ps_stack_get_biggest(stack);
	if (node->value > biggest->value)
		node->target = smallest;
	else if (node->value < smallest->value)
		node->target = biggest;
	else
	{
		closest = NULL;
		while (stack)
		{
			if (stack->value < node->value)
			{
				if (closest == NULL)
					closest = stack;
				else if (closest->value < stack->value)
					closest = stack;
			}
			stack = stack->next;
		}
		node->target = closest;
	}
}

/*
 *	link a target (from stack src) to every node in stack (dst)
 *	assign each node in stack b a terget from stack a
 *	mode = 0 => closest smaller
 *	mode = 1 => closest bigger
 */
void	ps_stack_assign_targets(t_stack *dst, t_stack *src, int mode)
{
	while (src)
	{

		if (mode == 0)
			ps_assign_target_cs(dst, src);
		else if (mode == 1)
			ps_assign_target_cb(dst, src);
		src = src->next;
	}
}
