SRCS	= push_swap.c helper_functions.c helper_functions_part_two.c ft_split.c swap_and_push.c rotate.c get_and_check.c reverse_rotate.c sort.c sort_helper_functions.c
OBJS	= $(SRCS:.c=.o)
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= push_swap

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
