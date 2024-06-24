/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:15:04 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:15:05 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

t_stack	*ps_stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	else
	{
		while (stack->next)
			stack = stack->next;
		return (stack);
	}
}
