/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_sort_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:13:55 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:13:56 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

void	ps_stack_sthree(t_stack **stack_a)
{
	t_stack	*biggest;

	biggest = ps_stack_get_biggest(*stack_a);
	if (*stack_a == biggest)
		ra(stack_a);
	else if ((*stack_a)->next == biggest)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		ps_stack_swap(stack_a, 'a');
}
