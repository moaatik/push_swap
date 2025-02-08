/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:41:21 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/07 23:34:33 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smallest;

	if (stack_a->size <= 3)
		return (sort_three(stack_a));
	while (stack_a->size > 3)
	{
		smallest = get_smallest_value(stack_a);
		while (stack_a->top != smallest)
		{
			index_list(stack_a);
			if (smallest->index > stack_a->size / 2)
				reverse_rotate_a(stack_a, 1);
			else
				rotate_a(stack_a, 1);
		}
		push_b(stack_a, stack_b, 1);
	}
	sort_three(stack_a);
	push_a(stack_a, stack_b, 1);
	push_a(stack_a, stack_b, 1);
}

void	find_target(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_b;
	t_node	*current_a;

	current_b = stack_b->top;
	while (current_b)
	{
		current_a = stack_a->top;
		current_b->target = NULL;
		while (current_a)
		{
			if (current_a->value > current_b->value && \
			(!current_b->target || current_a->value < current_b->target->value))
				current_b->target = current_a;
			current_a = current_a->next;
		}
		if (!current_b->target)
			current_b->target = get_smallest_value(stack_a);
		current_b = current_b->next;
	}
}

void	move_to_stack_a(t_node *to_a_node, t_stack *stack_a, t_stack *stack_b)
{
	t_node	*target;

	target = to_a_node->target;
	while (stack_a->top != target || stack_b->top != to_a_node)
	{
		index_list(stack_a);
		index_list(stack_b);
		if ((target->index <= stack_a->size / 2 && stack_a->top != target) && \
		(to_a_node->index <= stack_b->size / 2 && stack_b->top != to_a_node))
			rotate_a_and_b(stack_a, stack_b, 1);
		else if ((target->index > stack_a->size / 2 && \
		to_a_node->index > stack_b->size / 2))
			reverse_rotate_a_and_b(stack_a, stack_b, 1);
		else if (target->index <= stack_a->size / 2 && stack_a->top != target)
			rotate_a(stack_a, 1);
		else if (to_a_node->index <= stack_b->size / 2 && \
		stack_b->top != to_a_node)
			rotate_b(stack_b, 1);
		else if (target->index > stack_a->size / 2)
			reverse_rotate_a(stack_a, 1);
		else if (to_a_node->index > stack_b->size / 2)
			reverse_rotate_b(stack_b, 1);
	}
	push_a(stack_a, stack_b, 1);
}

t_node	*find_min_cost_node(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*target;
	t_node	*min_cost_node;
	int		current_cost;
	int		min_cost;

	min_cost = 2147483647;
	current = stack_b->top;
	min_cost_node = current;
	while (current)
	{
		target = current->target;
		if (current->index == 1 && target->index == 1)
			return (current);
		current_cost = cost(target->index, current->index, stack_a, stack_b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			min_cost_node = current;
		}
		current = current->next;
	}
	return (min_cost_node);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smallest;

	while (stack_a->size > 5)
		push_b(stack_a, stack_b, 1);
	sort_five(stack_a, stack_b);
	while (stack_b->top)
	{
		index_list(stack_a);
		index_list(stack_b);
		find_target(stack_a, stack_b);
		move_to_stack_a(find_min_cost_node(stack_a, stack_b), stack_a, stack_b);
	}
	smallest = get_smallest_value(stack_a);
	index_list(stack_a);
	while (stack_a->top != smallest)
	{
		if (smallest->index > stack_a->size / 2)
			reverse_rotate_a(stack_a, 1);
		else
			rotate_a(stack_a, 1);
	}
}
