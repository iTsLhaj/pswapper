#ifndef STACK_H
#define STACK_H

# include <libftprintf.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <colors.h>
# include <libft.h>

typedef struct	s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
	int				value;
}	t_stack;

#ifndef ASCII_ART
#define ASCII_ART

#define ASCII_MAX_WRITTEN_CHARS		13
#define ASCII_BOX_HORIZONTAL_PIPE	"─"
#define ASCII_BOX_VERTICAL_PIPE		"│"
#define ASCII_BOX_TOP_RIGH_CORNER	"┐"
#define ASCII_BOX_TOP_LEFT_CORNER	"┌"
#define ASCII_BOX_BOT_RIGH_CORNER	"┘"
#define ASCII_BOX_BOT_LEFT_CORNER	"└"

/* stack drawing utils | functions */
void	ps_ascii_draw_bot(void);
void	ps_ascii_draw_mid(int n, bool empty);
void	ps_ascii_draw_top(void);
void	ps_draw_stack(t_stack *stack);
void	ps_draw_stacks(t_stack *first, t_stack *second);

#endif

/* parser utils | functions */
bool	ps_verify_single(char *args_);
bool	ps_verify_multi_(char **args_);

/* parser */
void	ps_argparse(t_stack	**stack, int argc, char **argv);

/* stack utils | functions */
t_stack	*ps_stack_last(t_stack *stack);
t_stack	*ps_stack_append(t_stack **stack, int n);
void	ps_stack_free(t_stack **stack);

#endif
