#include <stack.h>


void	ps_stack_swap(t_stack **stack)
{
	int	temp;

	if (*stack == NULL)
		return;
	if (ps_stack_length(*stack) == 1)
		return;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}