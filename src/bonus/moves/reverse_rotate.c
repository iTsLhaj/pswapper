#include <stack.h>

static void	ps_stack_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;

	last = ps_stack_last(*stack);
	temp = last->prev;
	if (!temp)
		return ;
	(*stack)->prev = last;
	last->next = *stack;
	last->prev = NULL;
	temp->next = NULL;
	*stack = last;
}

void	rra(t_stack **stack)
{
	ps_stack_reverse_rotate(stack);
}

void	rrb(t_stack **stack)
{
	ps_stack_reverse_rotate(stack);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ps_stack_reverse_rotate(stack_a);
	ps_stack_reverse_rotate(stack_b);
}
