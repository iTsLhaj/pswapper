#include <stack.h>


static int		ps_get_nsize(int n)
{
	unsigned int	nb;
	int				ct;

	ct = 0;
	if (n == 0)
		return (++ct);
	else
	{
		if (nb < 0)
		{
			nb = -n;
			ct++;
		}
		else
			nb = n;
	}
	while (n)
	{
		ct++;
		n /= 10;
	}
	return (ct);
}

static void		ps_setbounds(int n, int *min, int *max)
{
	int	size;
	int	mid;

	size = ps_get_nsize(n);
	mid = (ASCII_MAX_WRITTEN_CHARS - size) / 2;
	if ((mid * 2) + size == ASCII_MAX_WRITTEN_CHARS)
		*min = *max = mid;
	else
	{
		*min = mid;
		*max = *min + 1;
	}
}

void			ps_ascii_draw_top(void)
{
	int	i;

	i = -1;
	ft_printf("%s", ASCII_BOX_TOP_LEFT_CORNER);
	while (++i < 13)
		ft_printf("%s", ASCII_BOX_HORIZONTAL_PIPE);
	ft_printf("%s", ASCII_BOX_TOP_RIGH_CORNER);
}

void			ps_ascii_draw_bot(void)
{
	int	i;

	i = -1;
	ft_printf("%s", ASCII_BOX_BOT_LEFT_CORNER);
	while (++i < 13)
		ft_printf("%s", ASCII_BOX_HORIZONTAL_PIPE);
	ft_printf("%s", ASCII_BOX_BOT_RIGH_CORNER);
}

void			ps_ascii_draw_mid(int n, bool empty)
{
	int	i_size;
	int	right;
	int	left;
	int	i;

	i_size = ps_get_nsize(n);
	ps_setbounds(n, &right, &left);
	if (n < 0)
		left--;
	ft_printf("%s", ASCII_BOX_VERTICAL_PIPE);
	i = -1;
	while (++i < right)
		ft_printf(" ");
	if (empty)
		ft_printf("-");
	else
		ft_printf("%i", n);
	i = -1;
	while (++i < left)
		ft_printf(" ");
	ft_printf("%s", ASCII_BOX_VERTICAL_PIPE);
}
