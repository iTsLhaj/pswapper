#include <stack.h>

void	ps_stack_targetize(
	t_stack **dst, t_stack **src,
	t_stack *(*_get_closest)(t_stack *, t_stack *))
{
	t_stack	*head;

	head = *src;
	while (head)
	{
		head->target = _get_closest(*dst, head);
		head = head->next;
	}
}
