/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:14:18 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:14:19 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

static void	ps_stack_rotate(t_stack **stack)
{
	t_stack	*new_head;
	t_stack	*last;

	new_head = (*stack)->next;
	if (new_head == NULL)
		return ;
	last = ps_stack_last(*stack);
	new_head->prev = NULL;
	last->next = (*stack);
	(*stack)->next = NULL;
	(*stack)->prev = last;
	*stack = new_head;
}

void	ra(t_stack **stack)
{
	ps_stack_rotate(stack);
	ft_printf("r%c\n", 'a');
}

void	rb(t_stack **stack)
{
	ps_stack_rotate(stack);
	ft_printf("r%c\n", 'b');
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ps_stack_rotate(stack_a);
	ps_stack_rotate(stack_b);
	ft_printf("r%c\n", 'r');
}
