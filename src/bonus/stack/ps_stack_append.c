/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:15:00 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:15:01 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

t_stack	*ps_stack_append(t_stack **stack, int n)
{
	t_stack	*new;
	t_stack	*end;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	else
	{
		new->value = n;
		new->next = NULL;
		new->prev = NULL;
	}
	if (*stack == NULL)
		*stack = new;
	else
	{
		end = ps_stack_last(*stack);
		end->next = new;
		new->prev = end;
	}
	return (new);
}
