/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_leviosa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:14:02 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:14:03 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

void	ps_fly_on_your_own(t_stack **stack, t_stack *node, char label)
{
	int		op;

	op = -1;
	if (node->index > (ps_stack_length(*stack) / 2))
		op = 1;
	else
		op = 0;
	while (*stack != node)
	{
		if (op == 0)
		{
			if (label == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (label == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}
