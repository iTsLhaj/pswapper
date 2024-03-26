#ifndef STACK_H
#define STACK_H

# include <libftprintf.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <colors.h>
# include <libft.h>

typedef struct	s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
	int				value;
	int				index;
	int				pcost;
	int				price;
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
void	ps_draw_stack(t_stack *stack, char label);
void	ps_draw_stacks(t_stack *first, t_stack *second, char *labels);

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
bool	ps_stack_is_sorted(t_stack *stack);
int		ps_stack_length(t_stack *stack);

/* stack operations */
void	ps_stack_swap(t_stack **stack, char label);
void	ps_stack_push(t_stack **dst, t_stack **src, char label);
/*
void	ps_stack_rotate(t_stack **stack, char label);
void	ps_stack_reverse_rotate(t_stack **stack, char label);
*/
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* stack sorting utils */
t_stack	*ps_stack_get_biggest(t_stack *stack);
t_stack	*ps_stack_get_smallest(t_stack *stack);
void	ps_stack_assign_targets(t_stack *stack_a, t_stack *stack_b);
void	ps_stack_set_index(t_stack *stack);
int		ps_get_push_to_top_price(t_stack *stack, t_stack *node);
void	ps_setpp(t_stack **stack_a, t_stack **stack_b);
void	ps_set_price(t_stack **stack_b);
t_stack	*ps_get_cheapest(t_stack *stack);
// void	ps_stack_putontop(t_stack **stack, t_stack *node);
void	ps_stack_putontop(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b);

/* stack sorting functions ! */
void	ps_stack_sthree(t_stack **stack_a);
void	ps_stack_sfive(t_stack **stack_a, t_stack **stack_b);
void	ps_stack_smore(t_stack **stack_a, t_stack **stack_b);

#endif
