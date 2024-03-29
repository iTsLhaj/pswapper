#include <stack.h>

static int	cometh_helper(t_stack *stack, t_stack *node)
{
	int	median;

	median = ps_stack_length(stack) / 2;
	if (node->index <= median)
		return (node->index);
	else
		return (ps_stack_length(stack) - node->index);
}

/* cometh: The Tax Collector */
void	ps_cometh(t_stack	**stack_a, t_stack **stack_b)
{
	t_stack	*head;

	head = *stack_a;
	while (head)
	{
		head->pcost = cometh_helper(*stack_a, head);
		head = head->next;
	}
	head = *stack_b;
	while (head)
	{
		head->pcost = cometh_helper(*stack_b, head);
		head = head->next;
	}
	head = *stack_a;
	while (head)
	{
		head->price = head->pcost + head->target->pcost;
		head = head->next;
	}
}

t_stack	*ps_get_cheapest(t_stack *stack)
{
	t_stack	*cheapest_;

	cheapest_ = NULL;
	while (stack)
	{
		if (cheapest_ == NULL)
			cheapest_ = stack;
		else if (cheapest_->price > stack->price)
			cheapest_ = stack;
		stack = stack->next;
	}
	return (cheapest_);
}
