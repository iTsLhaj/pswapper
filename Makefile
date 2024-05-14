NAME	=	push_swap
BONUS	=	checker
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3
LIBS	=	lib/ft_printf/libftprintf.a	\
			lib/libft/libft.a
FILES	=	src/moves/push.c						\
			src/moves/reverse_rotate.c				\
			src/moves/rotate.c						\
			src/moves/swap.c						\
			src/parser/ps_parser_utils.c			\
			src/parser/ps_parser.c					\
			src/sorting/utils/ps_shift_back.c		\
			src/sorting/utils/ps_stack_biggest.c	\
			src/sorting/utils/ps_stack_indexer.c	\
			src/sorting/utils/ps_stack_leviosa.c	\
			src/sorting/utils/ps_stack_smallest.c	\
			src/sorting/utils/ps_stack_to_array.c	\
			src/sorting/ps_sort_chunks.c			\
			src/sorting/ps_stack_sort_five.c		\
			src/sorting/ps_stack_sort_three.c		\
			src/stack/ps_stack_append.c				\
			src/stack/ps_stack_free.c				\
			src/stack/ps_stack_is_sorted.c			\
			src/stack/ps_stack_last.c				\
			src/stack/ps_stack_length.c				\
			src/main.c
OBJS	=	$(FILES:.c=.o)
BFILES	=	lib/gnl/get_next_line.c						\
			lib/gnl/get_next_line_utils.c				\
			src/bonus/parser/ps_parser_utils.c			\
			src/bonus/parser/ps_parser.c				\
			src/bonus/stack/ps_stack_append.c			\
			src/bonus/stack/ps_stack_free.c				\
			src/bonus/stack/ps_stack_is_sorted.c		\
			src/bonus/stack/ps_stack_last.c				\
			src/bonus/stack/ps_stack_length.c			\
			src/bonus/main.c
BOBJS	=	$(BFILES:.c=.o)

all: mklibs $(NAME)

bonus: mklibs $(BONUS)

mklibs:
	@make -C lib/libft
	@make -C lib/ft_printf

$(NAME): $(OBJS) $(LIBS)
	$(CC) -I include/ $(CFLAGS) $^ -o $@

$(BONUS): $(BOBJS) $(LIBS)
	$(CC) -I include/ $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) -I include/ $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(BOBJS)
	@make -C lib/libft clean
	@make -C lib/ft_printf clean

fclean:
	@rm -rf $(OBJS) $(BOBJS) $(BONUS) $(NAME)
	@make -C lib/libft fclean
	@make -C lib/ft_printf fclean

re: fclean $(NAME)
