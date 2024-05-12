#include <stack.h>

static int	get_index(int *array, int target, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (target == array[i])
			return (i);
		i++;
	}
	return (0);
}

int	ps_find_index(t_stack *stack, int ix, int n)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index <= ix || stack->index <= (ix + n))
			break;
		i++;
		stack = stack->next;
	}
	return (i);
}

void	ps_stack_set_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	ps_stack_indexer_v2(t_stack **stack, int *arr)
{
	t_stack	*stack_;

	stack_ = *stack;
	while (stack_)
	{
		stack_->index = get_index(
			arr, stack_->value, ps_stack_length(*stack));
		stack_ = stack_->next;
	}
}