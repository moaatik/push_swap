/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:23:33 by moaatik           #+#    #+#             */
/*   Updated: 2025/01/30 20:00:14 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size <= 0)
		return ;
	if (!stack_a->top)
	{
		stack_a->top = stack_b->top;
		stack_a->bottom = stack_a->top;
		stack_b->top = stack_b->top->next;
		stack_b->top->prev = NULL;
		stack_a->top->next = NULL;
	}
	else
	{
		stack_a->top->prev = stack_b->top;
		stack_b->top = stack_b->top->next;
		stack_a->top->prev->next = stack_a->top;
		stack_a->top = stack_a->top->prev;
		if (stack_b->top)
			stack_b->top->prev = NULL;
		stack_a->top->prev = NULL;
	}
	if (stack_a->bottom)
		stack_b->bottom = ft_lstlast(stack_b->top);
	stack_a->bottom = ft_lstlast(stack_a->top);
	manage_stack_size(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 0)
		return ;
	if (!stack_b->top)
	{
		stack_b->top = stack_a->top;
		stack_b->bottom = stack_b->top;
		stack_a->top = stack_a->top->next;
		stack_a->top->prev = NULL;
		stack_b->top->next = NULL;
	}
	else
	{
		stack_b->top->prev = stack_a->top;
		stack_a->top = stack_a->top->next;
		stack_b->top->prev->next = stack_b->top;
		stack_b->top = stack_b->top->prev;
		if (stack_a->top)
			stack_a->top->prev = NULL;
		stack_b->top->prev = NULL;
	}
	if (stack_a->bottom)
		stack_a->bottom = ft_lstlast(stack_a->top);
	stack_b->bottom = ft_lstlast(stack_b->top);
	manage_stack_size(stack_b, stack_a);
	write(1, "pb\n", 3);
}

void	swap_a(t_stack *stack_a, int print)
{
	t_node	*tmp;

	if (stack_a->size < 2)
		return ;
	tmp = stack_a->top->next;
	stack_a->top->next = tmp->next;
	stack_a->top->prev = tmp;
	if (tmp->next)
		tmp->next->prev = stack_a->top;
	tmp->next = stack_a->top;
	tmp->prev = NULL;
	stack_a->top = tmp;
	stack_a->bottom = ft_lstlast(stack_a->top);
	if (print)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack_b, int print)
{
	t_node	*tmp;

	if (stack_b->size < 2)
		return ;
	tmp = stack_b->top->next;
	stack_b->top->next = tmp->next;
	stack_b->top->prev = tmp;
	if (tmp->next)
		tmp->next->prev = stack_b->top;
	tmp->next = stack_b->top;
	tmp->prev = NULL;
	stack_b->top = tmp;
	stack_b->bottom = ft_lstlast(stack_b->top);
	if (print)
		write(1, "sb\n", 3);
}

void	swap_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	write(1, "ss\n", 3);
}
