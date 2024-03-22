#include <stack.h>


int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	ps_argparse(&stack_a, ac, av);
	// ps_draw_stack(stack_a);

	ps_stack_append(&stack_b, -1);
	ps_stack_append(&stack_b, 10);

	ps_draw_stack(stack_a, 'A');
	if (ps_stack_length(stack_a) == 3)
		ps_stack_sthree(&stack_a);
	ps_draw_stack(stack_a, 'A');
	// ps_draw_stacks(stack_a, stack_b, "AB");
	// ps_stack_rotate(&stack_a);
	// ps_stack_reverse_rotate(&stack_a);
	// ps_draw_stacks(stack_a, stack_b, "AB");
	// TODO: db b9aw lmoves and some additional functions ... !

	return 0;
}

