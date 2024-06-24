/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_shift_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:13:57 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:13:58 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

static int	_get_index(t_stack *stack, int target_value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == target_value)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

void	ps_shift_all(t_stack **stack_a, t_stack **stack_b)
{
	int	biggest;
	int	length;
	int	i;

	biggest = ps_stack_get_biggest(*stack_b)->value;
	length = ps_stack_length(*stack_b);
	i = _get_index(*stack_b, biggest);
	while (length)
	{
		if ((*stack_b)->value == biggest)
		{
			ps_stack_push(stack_a, stack_b, 'a');
			length--;
			if (*stack_b == NULL)
				biggest = 0;
			else
				biggest = ps_stack_get_biggest(*stack_b)->value;
			i = _get_index(*stack_b, biggest);
		}
		else if (i < (length / 2))
			rb(stack_b);
		else
			rrb(stack_b);
	}
}
