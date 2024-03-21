#include <stack.h>


void	ps_stack_push(t_stack **dst, t_stack **src)
{
	t_stack	*old_head;

	if (src == NULL || dst == NULL)
		return;
	if (*src == NULL)
		return;
	old_head = *src;
	*src = (*src)->next;
	(*src)->prev = NULL;
	if (*dst == NULL)
		*dst = old_head;
	else
	{
		(*dst)->prev = old_head;
		old_head->next = *dst;
		*dst = old_head;
	}
}