#include <stack.h>

void	ps_stack_sthree(t_stack **stack_a)
{
	t_stack	*biggest;

	biggest = ps_stack_get_biggest(*stack_a);
	if (*stack_a == biggest)
		ra(stack_a);
	else if ((*stack_a)->next == biggest)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		ps_stack_swap(stack_a, 'a');
}
