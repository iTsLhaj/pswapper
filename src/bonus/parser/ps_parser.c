/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:14:29 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/18 21:27:13 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

static void	ps_raise_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static char	*stringify(int ac, char **av)
{
	char	*string;
	char	*temp;
	int		index;

	string = NULL;
	index = 1;
	while (index < ac)
	{
		if (invalid((char *)av[index]))
		{
			free(string);
			ps_raise_error();
		}
		temp = string;
		string = join(ft_strjoin(string, av[index++]));
		free(temp);
	}
	return (string);
}

static int	check_list(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = 0;
		if ((list[i][j] == '-' && list[i][j + 1] != '\0')

			|| (list[i][j] == '+' && list[i][j + 1] != '\0'))
			j++;
		if (ft_isalldigit(&list[i][j]))
			return (1);
		i++;
	}
	return (0);
}

static void	check_duplicates(t_stack **stack)
{
	t_stack	*stack_;

	stack_ = *stack;
	while (stack_)
	{
		if (fetch(stack, stack_->value) > 1)
		{
			ps_stack_free(stack);
			ps_raise_error();
		}
		stack_ = stack_->next;
	}
}

void	ft_parser(t_stack **stack, int ac, char **av)
{
	char	*str;
	char	**lst;
	int		i;
	int		j;

	i = 0;
	str = stringify(ac, av);
	lst = ft_split(str, ' ');
	free(str);
	if (check_list(lst))
		i = -1;
	else
		ps_fill_stack(stack, lst);
	j = 0;
	while (lst[j])
		free(lst[j++]);
	free(lst);
	if (i == -1)
		ps_raise_error();
	check_duplicates(stack);
}
