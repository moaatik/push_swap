/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:34:43 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/24 19:46:54 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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
int		check_duplicate_in_stack(t_stack *stack_a);
int		check_invalid_input(char **strs, int strs_len, int i);
int		already_sorted(t_stack *stack_a);
int		cost(int t_index, int c_index, t_stack *stack_a, t_stack *stack_b);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack);
void	push_to_stack_b(t_stack *stack_a, t_stack *stack_b);
t_node	*get_smallest_value(t_stack *stack_a);
int		get(t_stack *a, int argc, char **argv, t_stack *b);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str, int *error);
t_stack	*ft_stacknew(void);
t_node	*ft_lstnew(int value, t_stack *a, t_stack *b, char **strs);
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
size_t	ft_strlen(const char *s);

#endif
