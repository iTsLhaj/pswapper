#include <stack.h>


static void	ps_stack_rotate(t_stack **stack)
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
	ps_stack_set_index(*stack);
}

/*
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
 */

void	ra(t_stack **stack)
{
	ps_stack_rotate(stack);
	ft_printf("r%c\n", 'a');
}

void	rb(t_stack **stack)
{
	ps_stack_rotate(stack);
	ft_printf("r%c\n", 'b');
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ps_stack_rotate(stack_a);
	ps_stack_rotate(stack_b);
	ft_printf("r%c\n", 'r');
}