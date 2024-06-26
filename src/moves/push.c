/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:14:15 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:14:16 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

void	ps_stack_push(t_stack **dst, t_stack **src, char label)
{
	t_stack	*old_head;

	if (src == NULL || dst == NULL)
		return ;
	if (*src == NULL)
		return ;
	old_head = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dst == NULL)
	{
		*dst = old_head;
		(*dst)->next = NULL;
		(*dst)->prev = NULL;
	}
	else
	{
		(*dst)->prev = old_head;
		old_head->next = *dst;
		*dst = old_head;
	}
	ft_printf("p%c\n", label);
}
