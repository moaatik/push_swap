SRCS	= push_swap.c helper_functions.c helper_functions_part_two.c ft_split.c swap_and_push.c rotate.c get_and_check.c reverse_rotate.c sort.c sort_helper_functions.c
BONUS_SRCS = checker_bonus.c ft_split.c swap_and_push.c rotate.c get_and_check.c reverse_rotate.c get_next_line_bonus.c get_next_line_utils_bonus.c helper_functions.c sort_helper_functions.c helper_functions_part_two.c 
OBJS	= $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= push_swap
BONUS_NAME = checker

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: clean
