#include <stack.h>

static bool	ps_is_forbidden(char c)
{
	char	*allowed;

	allowed = "0123456789-+";
	while (*allowed)
	{
		if (*allowed == c)
			return (false);
		allowed++;
	}
	return (true);
}

bool	ps_verify_single(char *args_)
{
	while (*args_)
	{
		if (ps_is_forbidden(*args_))
			return (false);
		args_++;
	}
	return (true);
}

bool	ps_verify_multi_(char **args_)
{
	int	i;

	i = 0;
	while (args_[i])
	{
		if (!ps_verify_single(args_[i]))
			return (false);
		i++;
	}
	return (true);
}

void	ps_raise_error(void)
{
	ft_printf("%sError\n%s", BRED, COLOR_RESET);
	exit(1);
}

bool	ps_contain_space(char *arg)
{
	while (*arg)
	{
		if (*arg == ' ')
			return (true);
		arg++;
	}
	return (false);
}
