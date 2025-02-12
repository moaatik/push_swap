/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:53:05 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/09 16:49:28 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_total_moves(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_minimum_moves(int a, int b)
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
		return (get_total_moves(rotate_a, rotate_b));
	if (c_index > stack_b->size / 2 && t_index > stack_a->size / 2)
		return (get_total_moves(reverse_rotate_a, reverse_rotate_b));
	return (get_minimum_moves(rotate_a + reverse_rotate_b, \
		reverse_rotate_a + rotate_b));
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

void	manage_size_and_print(t_stack *up, t_stack *down, int print, char c)
{
	if (print && c == 'a')
		write(1, "pa\n", 3);
	else if (print && c == 'b')
		write(1, "pb\n", 3);
	up->size++;
	down->size--;
}
