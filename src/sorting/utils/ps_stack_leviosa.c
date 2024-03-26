#include <stack.h>


void		ps_stack_putontop(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
{
	if (stack_a && node_a)
	{
		if (node_a->index > (ps_stack_length(*stack_a) / 2))
		{
			while (*stack_a != node_a)
				rra(stack_a);
		}
		else
		{
			while (*stack_a != node_a)
				ra(stack_a);
		}
	}
	if (stack_b && node_b)
	{
		if (node_b->index > (ps_stack_length(*stack_b) / 2))
		{
			while (*stack_b != node_b)
				rrb(stack_b);
		}
		else
		{
			while (*stack_b != node_b)
				rb(stack_b);
		}
	}
}

// static int	*set_median(t_stack **stack_a, t_stack **stack_b)
//  {
//  	int	*medians;
//
//  	medians = (int *)malloc(sizeof(int) * 2);
//  	if (stack_a == NULL || stack_b == NULL)
//  		return (NULL);
//  	if (*stack_a)
//  		medians[0] = (ps_stack_length(*stack_a) / 2);
//  	else
//  		medians[0] = -1;
//  	if (*stack_b)
//  		medians[1] = (ps_stack_length(*stack_b) / 2);
//  	else
//  		medians[1] = -1;
//  	return (medians);
//  }
//
// void		ps_stack_putontop(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
//  {
//  	int	*medians;
//  	t_stack	*bottoms[2];
//
//  	medians = set_median(stack_a, stack_b);
//  	bottoms[0] = ps_stack_last(*stack_a);
//  	bottoms[1] = ps_stack_last(*stack_b);
//  	if (node_a == bottoms[0] && node_b == bottoms[1])
//  	{
//  		rrr(stack_a, stack_b);
//  		return;
//  	}
//  	if (medians[0] != -1 && medians[1] != -1)
//  	{
//  		if (node_a->index <= medians[0] && node_b->index <= medians[1])
//  		{
//  			while (node_a->index <= medians[0] && node_b->index <= medians[1])
//  				rr(stack_a, stack_b);
//  		}
//  		else
//  		{
//  			while (node_a->index > medians[0] && node_b->index > medians[1])
//  				rrr(stack_a, stack_b);
//  		}
//  	}
//  	else
//  	{
//  		if (medians[0] != -1 && medians[1] == -1)
//  		{
//  			if (node_a->index <= medians[0])
//  			{
//  				while (node_a->index <= medians[0])
//  					ra(stack_a);
//  			}
//  			else
//  			{
//  				while (node_a->index > medians[0])
//  					rra(stack_a);
//  			}
//  		}
//  		else if (medians[0] == -1 && medians[1] != -1)
//  		{
//  			if (node_b->index <= medians[1])
//  			{
//  				while (node_b->index <= medians[1])
//  					rb(stack_b);
//  			}
//  			else
//  			{
//  				while (node_b->index > medians[1])
//  					rrb(stack_b);
//  			}
//  		}
//  	}
// 	free(medians);
//  }





