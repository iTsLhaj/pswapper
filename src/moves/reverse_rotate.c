#include <stack.h>


void	ps_stack_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;

	last = ps_stack_last(*stack);
	temp = last->prev;
	if (!temp)
		return;
	(*stack)->prev = last;
	last->next = *stack;
	last->prev = NULL;
	temp->next = NULL;
	*stack = last;
}