/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:14:33 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:14:34 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

static void	ps_stack_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;

	if (*stack == NULL)
		return ;
	last = ps_stack_last(*stack);
	temp = last->prev;
	if (!temp)
		return ;
	(*stack)->prev = last;
	last->next = *stack;
	last->prev = NULL;
	temp->next = NULL;
	*stack = last;
}

void	rra(t_stack **stack)
{
	ps_stack_reverse_rotate(stack);
}

void	rrb(t_stack **stack)
{
	ps_stack_reverse_rotate(stack);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ps_stack_reverse_rotate(stack_a);
	ps_stack_reverse_rotate(stack_b);
}
