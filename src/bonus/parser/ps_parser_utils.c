#include <stack.h>

int	invalid(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
	return (j == i);
}

char	*join(char *s)
{
	char	*p;

	p = ft_strjoin(s, " ");
	free(s);
	return (p);
}

int	ft_isalldigit(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}

int	fetch(t_stack **stack_a, int target)
{
	t_stack	*stack;
	int		count;

	stack = *stack_a;
	count = 0;
	while (stack)
	{
		if (stack->value == target)
			count++;
		stack = stack->next;
	}
	return (count);
}
