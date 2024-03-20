#include <stack.h>


static void	ps_draw_box(int	n, bool e)
{
	ps_ascii_draw_top();
	ft_printf("\n");
	ps_ascii_draw_mid(n, e);
	ft_printf("\n");
	ps_ascii_draw_bot();
	ft_printf("\n");
}

static void	ps_draw_boxes(t_stack *f, t_stack *s)
{
	int		n1;
	int		n2;
	bool	e1;
	bool	e2;

	n1 = 0;
	n2 = n1;
	e1 = false;
	e2 = e1;
	if (f == NULL)
		e1 = true;
	else
		n1 = f->value;
	if (s == NULL)
		e2 = true;
	else
		n2 = s->value;
	ft_printf("\n");
	ps_ascii_draw_top();
	ft_printf("\t");
	ps_ascii_draw_top();
	ft_printf("\n");
	ps_ascii_draw_mid(n1, e1);
	ft_printf("\t");
	ps_ascii_draw_mid(n2, e2);
	ft_printf("\n");
	ps_ascii_draw_bot();
	ft_printf("\t");
	ps_ascii_draw_bot();
	ft_printf("\n");
}

void		ps_draw_stack(t_stack *stack)
{
	while (stack)
	{
		ps_draw_box(stack->value, false);
		stack = stack->next;
	}
}

void		ps_draw_stacks(t_stack *first, t_stack *second)
{
	while (first || second)
	{
		ps_draw_boxes(first, second);
		if (first)
			first = first->next;
		if (second)
			second = second->next;
	}
}