/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:34:43 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/24 20:11:10 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_instruction
{
	char					*instruction;
	struct s_instruction	*next;
}	t_instruction;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}	t_node;

typedef struct s_stack
{
	int				size;
	t_node			*top;
	t_node			*bottom;
}					t_stack;

char			**ft_split(char const *s, char c);
int				get(t_stack *a, int argc, char **argv, t_stack *b);
int				check_instruction(char *str);
int				check_range_and_duplicated_numbers(int argc, char **argv);
int				already_sorted(t_stack *stack_a);
int				check_duplicate_in_stack(t_stack *stack_a);
long			ft_atoi(const char *str, int *error);
int				check_invalid_input(char **strs, int strs_len, int i);
void			ft_lstadd_back(t_node **lst, t_node *new);
t_stack			*ft_stacknew(void);
t_node			*ft_lstnew(int value, t_stack *a, t_stack *b, char **strs);
int				ft_lstsize(t_node *lst);
t_node			*ft_lstlast(t_node *lst);
void			ft_lstclear(t_node *lst);
void			ft_error(void);
void			free_stacks(t_stack **stack_a, t_stack **stack_b);
void			free_strs(char **strs);
char			*get_next_line(int fd);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			reverse_rotate_a(t_stack *stack_a, int print);
void			reverse_rotate_b(t_stack *stack_b, int print);
void			reverse_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b, \
				int print);
void			rotate_a(t_stack *stack_a, int print);
void			rotate_b(t_stack *stack_b, int print);
void			rotate_a_and_b(t_stack *stack_a, t_stack *stack_b, int print);
void			push_a(t_stack *stack_a, t_stack *stack_b, int print);
void			push_b(t_stack *stack_a, t_stack *stack_b, int print);
void			manage_size_and_print(t_stack *up, t_stack *down, \
				int print, char c);
void			swap_a(t_stack *stack_a, int print);
void			swap_b(t_stack *stack_b, int print);
void			swap_a_and_b(t_stack *stack_a, t_stack *stack_b, int print);
void			ft_lstadd_back_instruction(t_instruction **lst, \
				t_instruction *new);
int				ft_strcmp(const char *s1, const char *s2);
void			free_instructions(t_instruction *instructions);
t_instruction	*ft_lstnew_instruction(char *str, t_stack *stack_a, \
	t_stack *stack_b, t_instruction *instructions);

#endif
