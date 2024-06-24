/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:14:27 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/18 21:26:50 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*unzero(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0' && str[i])
		i++;
	return (ft_substr(str, i, ft_strlen(str)));
}
