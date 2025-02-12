SRCS = mandatory/push_swap.c \
       mandatory/helper_functions.c \
       mandatory/helper_functions_part_two.c \
       mandatory/ft_split.c \
       mandatory/swap_and_push.c \
       mandatory/rotate.c \
       mandatory/get_and_check.c \
       mandatory/reverse_rotate.c \
       mandatory/sort.c \
       mandatory/sort_helper_functions.c \
       mandatory/sort_helper_functions_part_2.c \

BONUS_SRCS = bonus/checker_bonus.c \
             bonus/ft_split_bonus.c \
             bonus/get_and_check_bonus.c \
             bonus/get_next_line_bonus.c \
             bonus/get_next_line_utils_bonus.c \
             bonus/helper_functions_bonus.c \
             bonus/helper_functions_part_two_bonus.c \
             bonus/helper_functions_part_three_bonus.c \
             bonus/reverse_rotate_bonus.c \
             bonus/rotate_bonus.c \
             bonus/swap_and_push_bonus.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

mandatory/%.o: mandatory/%.c mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/checker_bonus.h
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
