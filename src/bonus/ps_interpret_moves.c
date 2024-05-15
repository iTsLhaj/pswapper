#include <stack.h>

static void	ps_raise_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	get_move(char *move_)
{
	if (!ft_strncmp("ra\n", move_, 3))
		return (1);
	else if (!ft_strncmp("rb\n", move_, 3))
		return (2);
	else if (!ft_strncmp("rr\n", move_, 3))
		return (3);
	else if (!ft_strncmp("sa\n", move_, 3))
		return (4);
	else if (!ft_strncmp("sb\n", move_, 3))
		return (5);
	else if (!ft_strncmp("ss\n", move_, 3))
		return (6);
	else if (!ft_strncmp("pa\n", move_, 3))
		return (7);
	else if (!ft_strncmp("pb\n", move_, 3))
		return (8);
	else if (!ft_strncmp("rrb\n", move_, 4))
		return (9);
	else if (!ft_strncmp("rra\n", move_, 4))
		return (10);
	else if (!ft_strncmp("rrr\n", move_, 4))
		return (11);
	return (0);
}

static void	apply_move(t_stack **stack_a, t_stack **stack_b, char *move_)
{
	if (!ft_strncmp("ra\n", move_, 3))
		ra(stack_a);
	else if (!ft_strncmp("rb\n", move_, 3))
		rb(stack_b);
	else if (!ft_strncmp("rr\n", move_, 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp("sa\n", move_, 3))
		ps_stack_swap(stack_a, 'a');
	else if (!ft_strncmp("sb\n", move_, 3))
		ps_stack_swap(stack_b, 'b');
	else if (!ft_strncmp("ss\n", move_, 3))
	{
		ps_stack_swap(stack_a, 'a');
		ps_stack_swap(stack_b, 'b');
	}
	else if (!ft_strncmp("pa\n", move_, 3))
		ps_stack_push(stack_a, stack_b, 'a');
	else if (!ft_strncmp("pb\n", move_, 3))
		ps_stack_push(stack_b, stack_a, 'b');
	else if (!ft_strncmp("rra\n", move_, 4))
		rra(stack_a);
	else if (!ft_strncmp("rrb\n", move_, 4))
		rrb(stack_b);
	else if (!ft_strncmp("rrr\n", move_, 4))
		rrr(stack_a, stack_b);
}

void	ps_check_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (!get_move(move))
		{
			ps_stack_free(stack_a);
			ps_stack_free(stack_b);
			ps_raise_error();
		}
		apply_move(stack_a, stack_b, move);
		free(move);
		move = get_next_line(0);
	}
	free(move);
}
