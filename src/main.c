/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:13:32 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:13:33 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (!ps_stack_is_sorted(stack_a))
		{
			if (ps_stack_length(stack_a) == 2)
				ps_stack_swap(&stack_a, 'a');
			else if (ps_stack_length(stack_a) == 3)
				ps_stack_sthree(&stack_a);
			else if (ps_stack_length(stack_a) <= 5)
				ps_stack_sfive(&stack_a, &stack_b);
			else
				ps_sort_chunks(&stack_a, &stack_b);
		}
		ps_stack_free(&stack_a);
	}
	else
		write(2, "Error\n", 6);
}
