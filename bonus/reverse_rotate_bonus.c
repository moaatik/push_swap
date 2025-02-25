/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:37:55 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/14 19:35:38 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	reverse_rotate_a(t_stack *stack_a, int print)
{
	if (stack_a->size < 2)
		return ;
	stack_a->bottom->prev->next = NULL;
	stack_a->bottom->prev = NULL;
	stack_a->bottom->next = stack_a->top;
	stack_a->top->prev = stack_a->bottom;
	stack_a->top = stack_a->bottom;
	stack_a->bottom = ft_lstlast(stack_a->top);
	if (print)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack_b, int print)
{
	if (stack_b->size < 2)
		return ;
	stack_b->bottom->prev->next = NULL;
	stack_b->bottom->prev = NULL;
	stack_b->bottom->next = stack_b->top;
	stack_b->top->prev = stack_b->bottom;
	stack_b->top = stack_b->bottom;
	stack_b->bottom = ft_lstlast(stack_b->top);
	if (print)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b, int print)
{
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	if (print)
		write(1, "rrr\n", 4);
}

void	free_instructions(t_instruction *instructions)
{
	t_instruction	*tmp;

	while (instructions)
	{
		tmp = instructions->next;
		free(instructions->instruction);
		free(instructions);
		instructions = tmp;
	}
}
