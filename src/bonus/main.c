#include <stack.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	(void)stack_b;
	if (ac >= 2)
	{
		ps_argparse(&stack_a, ac, av);
		tmp = stack_a;
		while (tmp)
		{
			ft_printf("%i\n", tmp->value);
			tmp = tmp->next;
		}

	}
	else
		write(2, "Error\n", 6);
}
