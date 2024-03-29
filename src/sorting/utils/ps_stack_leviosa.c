#include <stack.h>

static int	ps_set_instructions(t_fly *data, int *op_cfg)
{
	op_cfg[0] = -1;
	op_cfg[1] = -1;

	if (data->f_node->index > (ps_stack_length((*data->f_stack)) / 2))
		op_cfg[0] = 1;
	else
		op_cfg[0] = 0;
	if (data->s_node->index > (ps_stack_length((*data->s_stack)) / 2))
		op_cfg[1] = 1;
	else
		op_cfg[1] = 0;
	return (0);
}


void	ps_fly_on_your_own(t_stack **stack, t_stack *node, char label)
{
	int		op;

	op = -1;
	if (node->index > (ps_stack_length(*stack) / 2))
		op = 1;
	else
		op = 0;
	while (*stack != node)
	{
		if (op == 0)
		{
			if (label == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (label == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void		ps_stack_putontop(t_fly *data)
{
	int	ops[2];
	int	op;

	op = -1;
	ps_set_instructions(data, ops);
	if (ops[0] != ops[1])
	{
		ps_fly_on_your_own(data->f_stack, data->f_node, data->label[0]);
		ps_fly_on_your_own(data->s_stack, data->s_node, data->label[1]);
	}
	else
	{
		op = ops[0];
		while ((*data->f_stack) != data->f_node && (*data->s_stack) != data->s_node)
		{
			if (op == 0)
				rr(data->f_stack, data->s_stack);
			else
				rrr(data->f_stack, data->s_stack);
		}
		ps_fly_on_your_own(data->f_stack, data->f_node, data->label[0]);
		ps_fly_on_your_own(data->s_stack, data->s_node, data->label[1]);
	}
}