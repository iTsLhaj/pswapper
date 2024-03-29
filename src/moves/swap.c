#include <stack.h>

void	ps_stack_swap(t_stack **stack, char label)
{
	int	temp;

	if (*stack == NULL)
		return ;
	if (ps_stack_length(*stack) == 1)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	ps_stack_set_index(*stack);
	ft_printf("s%c\n", label);
}
