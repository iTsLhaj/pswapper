#include <stack.h>


t_stack	*ps_get_cheapest(t_stack *stack)
{
	t_stack	*cheapest;

	cheapest = NULL;
	while (stack)
	{
		if (!cheapest)
			cheapest = stack;
		else if (stack->price <= cheapest->price)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	ps_setpp(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;

	head = *stack_a;
	while (head)
	{
		head->pcost = ps_get_push_to_top_price(*stack_a, head);
		head = head->next;
	}
	head = *stack_b;
	while (head)
	{
		head->pcost = ps_get_push_to_top_price(*stack_b, head);
		head = head->next;
	}
}

int		ps_get_push_to_top_price(t_stack *stack, t_stack *node)
{
	int	median;

	median = ps_stack_length(stack) / 2;
	if (node->index <= median)
		return (node->index);
	else
		return (ps_stack_length(stack) - node->index);
}

void	ps_set_price(t_stack **stack_b)
{
	t_stack	*stack;

	stack = *stack_b;
	while (stack)
	{
		stack->price = stack->pcost + stack->target->pcost + 1;
		stack = stack->next;
	}
}
