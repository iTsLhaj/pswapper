#include <stack.h>


int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 2)
	{
		ps_argparse(&stack_a, ac, av);
		if (!ps_stack_is_sorted(stack_a))
		{
			ps_stack_set_index(stack_a);
			if (ps_stack_length(stack_a) == 2)
				ps_stack_swap(&stack_a, 'a');
			else if (ps_stack_length(stack_a) == 3)
			{
				ps_stack_sthree(&stack_a);
				// ps_draw_stacks(stack_a, stack_b, "AB");
			}
			else if (ps_stack_length(stack_a) <= 5)
				ps_stack_sfive(&stack_a, &stack_b);
			else
				ps_stack_smore(&stack_a, &stack_b);
			// else if (ps_stack_length(stack_a) <= 5)
		}
		ps_stack_free(&stack_a);
		// ps_draw_stacks(stack_a, stack_b, "AB");
	}
	return 0;
}

