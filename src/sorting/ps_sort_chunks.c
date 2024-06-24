/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:13:52 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/17 18:13:53 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

static void	candy_crush(
	t_stack **stack_a,
	t_stack **stack_b,
	int *numbers,
	int n
)
{
	int	i;
	int	length;

	i = 0;
	length = ps_stack_length(*stack_a);
	ps_stack_indexer_v2(stack_a, numbers);
	while (i < length)
	{
		if ((*stack_a)->index <= i)
		{
			ps_stack_push(stack_b, stack_a, 'b');
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (i + n))
		{
			ps_stack_push(stack_b, stack_a, 'b');
			i++;
		}
		else if (
			ps_find_index(*stack_a, i, n) < (ps_stack_length(*stack_a) / 2))
			ra(stack_a);
		else
			rra(stack_a);
	}
}

static void	_sort_array(int *array, int size)
{
	int	x;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				x = array[i];
				array[i] = array[j];
				array[j] = x;
			}
			j++;
		}
		i++;
	}
}

void	ps_sort_chunks(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk_size;
	int	*array_;

	chunk_size = 15;
	if (ps_stack_length(*stack_a) > 400)
		chunk_size *= 2;
	array_ = ps_stack_to_array(*stack_a, (void *)0);
	_sort_array(array_, ps_stack_length(*stack_a));
	candy_crush(stack_a, stack_b, array_, chunk_size);
	ps_shift_all(stack_a, stack_b);
	free(array_);
}
