/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:19:04 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/12 16:36:01 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack_a, int print)
{
	t_node	*temp;

	if (stack_a->size < 2)
		return ;
	stack_a->bottom->next = stack_a->top;
	stack_a->top->prev = stack_a->bottom;
	stack_a->top->next->prev = NULL;
	temp = stack_a->top->next;
	stack_a->top->next = NULL;
	stack_a->top = temp;
	stack_a->bottom = ft_lstlast(stack_a->top);
	if (print)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack_b, int print)
{
	t_node	*temp;

	if (stack_b->size < 2)
		return ;
	stack_b->bottom->next = stack_b->top;
	stack_b->top->prev = stack_b->bottom;
	stack_b->top->next->prev = NULL;
	temp = stack_b->top->next;
	stack_b->top->next = NULL;
	stack_b->top = temp;
	stack_b->bottom = ft_lstlast(stack_b->top);
	if (print)
		write(1, "rb\n", 3);
}

void	rotate_a_and_b(t_stack *stack_a, t_stack *stack_b, int print)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	if (print)
		write(1, "rr\n", 3);
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstclear((*stack_a)->top);
	free(*stack_a);
	ft_lstclear((*stack_b)->top);
	free(*stack_b);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
