#include <stack.h>

static void	ps_parse_smol(t_stack **stack, char **argv)
{
	int		i;
	char	**args;

	if (!ps_contain_space(argv[1]))
	{
		if (!ps_verify_single(argv[1]))
			ps_raise_error();
		ps_stack_append(stack, ft_atoi(argv[1]));
	}
	else
	{
		args = ft_split(argv[1], ' ');
		if (!ps_verify_multi_(args))
		{
			free(args);
			ps_raise_error();
		}
		i = 0;
		while (args[i])
			ps_stack_append(stack, ft_atoi(args[i++]));
	}
}

static void	ps_parse_big(t_stack **stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ps_verify_single(argv[i]))
		{
			if (*stack)
				ps_stack_free(stack);
			ps_raise_error();
		}
		ps_stack_append(stack, ft_atoi(argv[i]));
		i++;
	}
}

void	ps_argparse(t_stack	**stack, int argc, char **argv)
{
	if (argc == 2)
		ps_parse_smol(stack, argv);
	else
		ps_parse_big(stack, argc, argv);
}
