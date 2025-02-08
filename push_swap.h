/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:34:43 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/07 22:43:10 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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

int		check_range_and_duplicated_numbers(int argc, char **argv);
int		check_invalid_input(char **strs, int strs_len, int i);
int		already_sorted(t_stack *stack_a);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack);
int		cost(int t_index, int c_index, t_stack *stack_a, t_stack *stack_b);
t_node	*get_smallest_value(t_stack *stack_a);
void	get(t_stack *a, int argc, char **argv);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
t_stack	*ft_stacknew(void);
t_node	*ft_lstnew(int value);
int		ft_lstsize(t_node *lst);
t_node	*ft_lstlast(t_node *lst);
void	index_list(t_stack *stack);
void	manage_size_and_print(t_stack *up, t_stack *down, int print, char c);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstclear(t_node *lst);
void	push_a(t_stack *stack_a, t_stack *stack_b, int print);
void	push_b(t_stack *stack_a, t_stack *stack_b, int print);
void	swap_a(t_stack *stack_a, int print);
void	swap_b(t_stack *stack_b, int print);
void	swap_a_and_b(t_stack *stack_a, t_stack *stack_b, int print);
void	rotate_a(t_stack *stack_a, int print);
void	rotate_b(t_stack *stack_b, int print);
void	rotate_a_and_b(t_stack *stack_a, t_stack *stack_b, int print);
void	reverse_rotate_a(t_stack *stack_a, int print);
void	reverse_rotate_b(t_stack *stack_b, int print);
void	reverse_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b, int print);
void	free_strs(char **strs);
void	free_stacks(t_stack **stack_a, t_stack **stack_b);
void	ft_error(void);

char	*get_next_line(int fd);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
