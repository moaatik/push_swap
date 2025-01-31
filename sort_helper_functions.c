/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:53:05 by moaatik           #+#    #+#             */
/*   Updated: 2025/01/31 15:33:24 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	cost(int t_index, int c_index, t_stack *stack_a, t_stack *stack_b)
{
	int	rotate_a;
	int	rotate_b;
	int	reverse_rotate_a;
	int	reverse_rotate_b;

	rotate_a = t_index;
	rotate_b = c_index;
	reverse_rotate_a = stack_a->size - t_index;
	reverse_rotate_b = stack_b->size - c_index;
	if (c_index <= stack_b->size / 2 && t_index <= stack_a->size / 2)
		return (get_max(rotate_a, rotate_b));
	if (c_index > stack_b->size / 2 && t_index > stack_a->size / 2)
		return (get_max(reverse_rotate_a, reverse_rotate_b));
	return (get_min(rotate_a + reverse_rotate_b, reverse_rotate_a + rotate_b));
}

t_node	*get_smallest_value(t_stack *stack_a)
{
	t_node	*current;
	t_node	*smallest;

	current = stack_a->top;
	smallest = stack_a->top;
	while (current)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

void	manage_stack_size(t_stack *up, t_stack *down)
{
	up->size++;
	down->size--;
}
