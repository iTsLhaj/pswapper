#include <stack.h>


static void	ps_draw_hbox(char label)
{
	ps_ascii_draw_top();
	ft_printf("\n%s      %c      %s\n", ASCII_BOX_VERTICAL_PIPE, label, ASCII_BOX_VERTICAL_PIPE);
	ps_ascii_draw_bot();
	ft_printf("\n");
}

static void	ps_draw_hboxes(char *labels)
{
	ps_ascii_draw_top();
	ft_printf("      \t");
	ps_ascii_draw_top();

	ft_printf("\n%s      %c      %s", ASCII_BOX_VERTICAL_PIPE, labels[0], ASCII_BOX_VERTICAL_PIPE);
	ft_printf("      \t");
	ft_printf("%s      %c      %s\n", ASCII_BOX_VERTICAL_PIPE, labels[1], ASCII_BOX_VERTICAL_PIPE);

	ps_ascii_draw_bot();
	ft_printf("      \t");
	ps_ascii_draw_bot();
	ft_printf("\n");
}

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
	ft_printf("      \t");
	ps_ascii_draw_top();
	ft_printf("\n");
	ps_ascii_draw_mid(n1, e1);
	if (f)
		ft_printf(" [%i] \t", f->index);
	else
		ft_printf(" [-] \t");
	ps_ascii_draw_mid(n2, e2);
	if (s)
		ft_printf(" [%i] \t", s->index);
	else
		ft_printf(" [-] \t");
	ft_printf("\n");
	ps_ascii_draw_bot();
	ft_printf("      \t");
	ps_ascii_draw_bot();
	ft_printf("\n");
}

void		ps_draw_stack(t_stack *stack, char label)
{
	ft_printf("\n\n─── [Stack] ───\n\n");
	ps_draw_hbox(label);
	ft_printf("\n");
	while (stack)
	{
		ps_draw_box(stack->value, false);
		stack = stack->next;
	}
}

void		ps_draw_stacks(t_stack *first, t_stack *second, char *labels)
{
	ft_printf("\n\n───────────────── [Stacks] ─────────────────\n\n");
	ps_draw_hboxes(labels);
	ft_printf("\n");
	while (first || second)
	{
		ps_draw_boxes(first, second);
		if (first)
			first = first->next;
		if (second)
			second = second->next;
	}
}