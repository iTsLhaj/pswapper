#include <stack.h>


void	ps_stack_rotate(t_stack **stack)
{
	t_stack	*new_head;
	t_stack	*last;

	new_head = (*stack)->next;
	last = ps_stack_last(*stack);
	new_head->prev = NULL;
	last->next = (*stack);
	(*stack)->next = NULL;
	(*stack)->prev = last;
	*stack = new_head;
}