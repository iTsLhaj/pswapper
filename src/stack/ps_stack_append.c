#include <stack.h>

t_stack	*ps_stack_append(t_stack **stack, int n)
{
	t_stack	*new;
	t_stack	*end;

	new = (t_stack *)malloc(sizeof(t_stack));
	ft_bzero((void *)new, sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	else
	{
		new->value = n;
		new->next = NULL;
		new->prev = NULL;
	}
	if (*stack == NULL)
		*stack = new;
	else
	{
		end = ps_stack_last(*stack);
		end->next = new;
		new->prev = end;
	}
	return (new);
}
