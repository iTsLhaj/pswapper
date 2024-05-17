#include <stack.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		ft_parser(&stack_a, ac, av);
		ps_check_moves(&stack_a, &stack_b);
		if (ps_stack_is_sorted(stack_a))
			write(2, "OK", 2);
		else
			write(2, "KO", 2);
	}
	else
		write(2, "Error\n", 6);
	ps_stack_free(&stack_a);
}
