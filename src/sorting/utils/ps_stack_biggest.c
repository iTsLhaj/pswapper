/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_biggest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:13:59 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:14:00 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

t_stack	*ps_stack_get_biggest(t_stack *stack)
{
	t_stack	*big;

	if (stack == NULL)
		return (NULL);
	big = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > big->value)
			big = stack;
		stack = stack->next;
	}
	return (big);
}
