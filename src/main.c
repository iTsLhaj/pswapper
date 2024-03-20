#include <stack.h>


int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	ps_argparse(&stack_a, ac, av);
	// ps_draw_stack(stack_a);

	stack_b = (t_stack *)malloc(sizeof(t_stack));
	stack_b->value = -1;
	stack_b->next = NULL;
	stack_b->prev = NULL;
	stack_b->target = NULL;

	ps_draw_stacks(stack_a, stack_b);
	// TODO: db b9aw lmoves and some additional functions ... !

	return 0;
}

