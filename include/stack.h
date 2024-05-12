

#ifndef STACK_H
# define STACK_H

# include <libftprintf.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <colors.h>
# include <libft.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
	int				value;
	int				index;
	int				pcost;
	int				price;
}	t_stack;

typedef struct s_fly
{
	t_stack	**f_stack;
	t_stack	**s_stack;
	t_stack	*f_node;
	t_stack	*s_node;
	char	*label;
}	t_fly;

/* parser utils | functions */
bool	ps_verify_single(char *args_);
bool	ps_verify_multi_(char **args_);
void	ps_raise_error(void);
bool	ps_contain_space(char *arg);

/* parser */
void	ps_argparse(t_stack	**stack, int argc, char **argv);

/* stack utils | functions */
t_stack	*ps_stack_last(t_stack *stack);
t_stack	*ps_stack_append(t_stack **stack, int n);
void	ps_stack_free(t_stack **stack);
bool	ps_stack_is_sorted(t_stack *stack);
int		ps_stack_length(t_stack *stack);
void	ps_stack_targetize(t_stack **dst, t_stack **src,
			t_stack *(*_get_closest)(t_stack *, t_stack *));

/* stack operations */
void	ps_stack_swap(t_stack **stack, char label);
void	ps_stack_push(t_stack **dst, t_stack **src, char label);

void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* stack sorting utils */
t_stack	*ps_stack_get_biggest(t_stack *stack);
t_stack	*ps_stack_get_smallest(t_stack *stack);
void	ps_stack_set_index(t_stack *stack);
void	ps_fly_on_your_own(t_stack **stack, t_stack *node, char label);
void	ps_stack_putontop(t_fly *data);
void	ps_cometh(t_stack	**stack_a, t_stack **stack_b);
t_stack	*ps_get_cheapest(t_stack *stack);
int		*ps_stack_to_array(t_stack *stack, int *size);
void	ps_stack_indexer_v2(t_stack **stack, int *arr);
int		ps_find_index(t_stack *stack, int ix, int n);
void	ps_shift_all(t_stack **stack_a, t_stack **stack_b);

/* stack sorting functions ! */
void	ps_stack_sthree(t_stack **stack_a);
void	ps_stack_sfive(t_stack **stack_a, t_stack **stack_b);
void	ps_stack_smore(t_stack **stack_a, t_stack **stack_b);
void	ps_sort_chunks(t_stack **stack_a, t_stack **stack_b);

#endif
