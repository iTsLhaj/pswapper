#include <stack.h>

void	ps_stack_sfive(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;

	while (ps_stack_length(*stack_a) > 3)
	{
		smallest = ps_stack_get_smallest(*stack_a);
		ps_fly_on_your_own(stack_a, smallest, 'a');
		ps_stack_push(stack_b, stack_a, 'b');
	}
	ps_stack_sthree(stack_a);
	while (ps_stack_length(*stack_b))
		ps_stack_push(stack_a, stack_b, 'a');
	if ((*stack_a)->value > (*stack_a)->next->value)
		ps_stack_swap(stack_a, 'a');
}
