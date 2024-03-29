#include <stack.h>

static t_stack	*get_smallest_closest(t_stack *stack, t_stack *node)
{
	t_stack	*closest;

	closest = NULL;
	if (node->value < ps_stack_get_smallest(stack)->value)
		return (ps_stack_get_biggest(stack));
	while (stack)
	{
		if (closest == NULL)
		{
			if (stack->value < node->value && stack->value > INT_MIN)
				closest = stack;
		}
		else
		{
			if (stack->value < node->value && stack->value > closest->value)
				closest = stack;
		}
		stack = stack->next;
	}
	return (closest);
}

static t_stack	*get_biggest_closest(t_stack *stack, t_stack *node)
{
	t_stack	*closest;
	t_stack	*smallest;

	closest = NULL;
	smallest = ps_stack_get_smallest(stack);
	while (stack)
	{
		if (closest == NULL)
		{
			if (stack->value > node->value && stack->value < INT_MAX)
				closest = stack;
		}
		else
		{
			if (stack->value > node->value && stack->value < closest->value)
				closest = stack;
		}
		stack = stack->next;
	}
	if (closest == NULL)
		return (smallest);
	return (closest);
}

static void	levitate(t_stack **stack_a, t_stack **stack_b, bool reverse)
{
	t_stack	*cheapest_;
	t_fly	data;

	data.f_stack = stack_a;
	data.s_stack = stack_b;
	data.label = "ab";
	if (reverse == false)
	{
		cheapest_ = ps_get_cheapest(*stack_a);
		data.f_node = cheapest_;
		data.s_node = cheapest_->target;
	}
	else
	{
		cheapest_ = ps_get_cheapest(*stack_b);
		data.f_node = cheapest_->target;
		data.s_node = cheapest_;
	}
	ps_stack_putontop(&data);
}

void	ps_stack_smore(t_stack **stack_a, t_stack **stack_b)
{
	ps_stack_push(stack_b, stack_a, 'b');
	ps_stack_push(stack_b, stack_a, 'b');
	while (ps_stack_length(*stack_a) != 3)
	{
		ps_stack_targetize(stack_b, stack_a, &get_smallest_closest);
		ps_cometh(stack_a, stack_b);
		levitate(stack_a, stack_b, false);
		ps_stack_push(stack_b, stack_a, 'b');
	}
	ps_stack_sthree(stack_a);
	while (ps_stack_length(*stack_b))
	{
		ps_stack_targetize(stack_a, stack_b, &get_biggest_closest);
		ps_cometh(stack_b, stack_a);
		levitate(stack_a, stack_b, true);
		ps_stack_push(stack_a, stack_b, 'a');
	}
	if (ps_stack_last(*stack_a) == ps_stack_get_smallest(*stack_a))
		rra(stack_a);
	while (!ps_stack_is_sorted(*stack_a))
		ra(stack_a);
}
