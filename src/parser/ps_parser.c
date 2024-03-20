#include <stack.h>


static void	ps_raise_error(void)
{
	ft_printf("%sError\n%s", BRED, COLOR_RESET);
	exit(1);
}

static bool	ps_contain_space(char *arg)
{
	while (*arg)
	{
		if (*arg == ' ')
			return (true);
		arg++;
	}
	return (false);
}

void		ps_argparse(t_stack	**stack, int argc, char **argv)
{
	char	**args;
	int		i;

	if (argc == 2)
	{
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
	else
	{
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
}