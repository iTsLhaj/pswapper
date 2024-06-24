/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:13:48 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:13:49 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

int	ps_stack_length(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
