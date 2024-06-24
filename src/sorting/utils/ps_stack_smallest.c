/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_smallest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:14:04 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:14:05 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

t_stack	*ps_stack_get_smallest(t_stack *stack)
{
	t_stack	*smol;

	if (stack == NULL)
		return (NULL);
	smol = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < smol->value)
			smol = stack;
		stack = stack->next;
	}
	return (smol);
}
