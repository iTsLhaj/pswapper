/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:26:13 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/18 21:26:31 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

static void	ps_raise_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static long int	ps_atoi(const char *n)
{
	long int	i;
	long int	r;
	long int	s;

	i = 0;
	r = 0;
	s = 1;
	while ((n[i] >= 9 && n[i] <= 13) || n[i] == 32)
		i++;
	if (n[i] == '-')
	{
		i++;
		s = -1;
	}
	else if (n[i] == '+')
		i++;
	while (n[i] <= '9' && n[i] >= '0')
		r = ((r * 10) + n[i++]) - '0';
	return (r * s);
}

static int	check_nbr(char *p)
{
	long int	n;
	char		*tmp;

	n = ps_atoi(p);
	tmp = unzero(p);
	if (ft_strlen(tmp) > 11 || n < INT_MIN || n > INT_MAX)
		return (free(tmp), 1);
	return (free(tmp), 0);
}

void	ps_fill_stack(t_stack **stack, char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		if (check_nbr(list[i]))
		{
			ps_stack_free(stack);
			j = 0;
			while (list[j])
				free(list[j++]);
			free(list);
			ps_raise_error();
		}
		ps_stack_append(
			stack, ft_atoi(list[i++]));
	}
}
