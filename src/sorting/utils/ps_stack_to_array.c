#include <stack.h>

int	*ps_stack_to_array(t_stack *stack, int *size_)
{
	int	i;
	int	size;
	int	*array;

	i = 0;
	size = ps_stack_length(stack);
	array = (int *)malloc(sizeof(int) * size);
	ft_bzero((void *)array, (sizeof(int) * size));
	while (stack)
	{
		array[i++] = stack->value;
		stack = stack->next;
	}
	if (size_)
		*size_ = size;
	return (array);
}
