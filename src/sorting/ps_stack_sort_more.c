#include <stack.h>


void		ps_stack_smore(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	t_stack	*smallest;
	t_stack	*biggest;

	ps_stack_push(stack_b, stack_a, 'b');
	ps_stack_push(stack_b, stack_a, 'b');
	while (ps_stack_length(*stack_a) != 3)
	{
		ps_stack_assign_targets(*stack_b, *stack_a, 0);
		ps_setpp(stack_a, stack_b);
		ps_set_price(stack_a);
		cheapest = ps_get_cheapest(*stack_a);
		ps_stack_putontop(stack_a, stack_b, cheapest, NULL);
		ps_stack_putontop(stack_a, stack_b, NULL, cheapest->target);
		ps_stack_push(stack_b, stack_a, 'b');
	}
	ps_stack_sthree(stack_a);
	while (ps_stack_length(*stack_b) != 0)
	{
		ps_stack_assign_targets(*stack_a, *stack_b, 1);
		ps_setpp(stack_a, stack_b);
		ps_set_price(stack_b);
		cheapest = ps_get_cheapest(*stack_b);
		ps_stack_putontop(stack_a, stack_b, NULL, cheapest);
		ps_stack_putontop(stack_a, stack_b, cheapest->target, NULL);
		ps_stack_push(stack_a, stack_b, 'a');
	}
	while (ps_stack_length(*stack_a))
	{
		biggest = ps_stack_get_biggest(*stack_a);
		ps_stack_putontop(stack_a, stack_b, biggest, NULL);
		ps_stack_push(stack_b, stack_a, 'b');
	}
	while (ps_stack_length(*stack_b))
		ps_stack_push(stack_a, stack_b, 'a');
	// ps_draw_stacks(*stack_a, *stack_b, "AB");
	// ft_printf("cheapest: {%p:%i} -> {%p:%i}\n", cheapest, cheapest->value, cheapest->target, cheapest->target->value);
}









































