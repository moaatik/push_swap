/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:41:21 by moaatik           #+#    #+#             */
/*   Updated: 2025/01/28 18:21:04 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//void    to_the_top_and_push(t_stack *stack, t_node *biggest, t_stack *other_stack)
//{
//	index_list(stack);
//	if (biggest->index == 1)
//	{
//		push_a(other_stack, stack);
//		return ;
//	}
//	if (biggest->index > stack->size/2)
//	{
//		while (biggest->index > stack->size/2)
//		{
//			reverse_rotate_b(stack, 0);
//			index_list(stack);
//		}
//	}
//	else
//	{
//		while (biggest->index > 1)
//		{
//			rotate_b(stack, 0);
//			index_list(stack);
//		}
//	}
//	push_a(other_stack, stack);
//}

void	sort_three(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		swap_a(stack, 1);
	if (stack->top->next->value > stack->bottom->value)
		reverse_rotate_a(stack, 1);
	if (stack->top->value > stack->top->next->value)
		swap_a(stack, 1);
}

//void	move_biggest_nodes(t_stack *stack, t_stack *other_stack)
//{
//	t_node	*current;
//	t_node	*biggest;
//	long	the_limit;
//	int	number_of_nodes;

//	the_limit = 2147483648;
//	number_of_nodes = stack->size;
//	while (number_of_nodes > 0)
//	{
//		current = stack->top;
//		biggest = NULL;
//		while (current)
//		{
//			if ((!biggest || current->value > biggest->value) && current->value < the_limit)
//				biggest = current;
//			current = current->next;
//		}
//		the_limit = biggest->value;
//		to_the_top_and_push(stack, biggest, other_stack);
//		number_of_nodes--;
//	}
//}

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
			if (current_a->value > current_b->value && (!current_b->target || current_a->value < current_b->target->value))
				current_b->target = current_a;
			current_a = current_a->next;
		}
		if (!current_b->target)
			current_b->target = get_smallest_value(stack_a);
		current_b = current_b->next;
	}
}

#include <stdio.h>

void	move_to_stack_a(t_node *to_a_node, t_stack *stack_a, t_stack *stack_b)
{
	t_node	*target;

	target = to_a_node->target;
	while (stack_a->top != target || stack_b->top != to_a_node)
	{
		index_list(stack_a);
		index_list(stack_b);
		if ((target->index <= stack_a->size/2 && stack_a->top != target) && (to_a_node->index <= stack_b->size/2 && stack_b->top != to_a_node))
			rotate_a_and_b(stack_a, stack_b);
		else if ((target->index > stack_a->size/2 && to_a_node->index > stack_b->size/2))
			reverse_rotate_a_and_b(stack_a, stack_b);
		else if (target->index <= stack_a->size/2 && stack_a->top != target)
			rotate_a(stack_a, 1);
		else if (to_a_node->index <= stack_b->size/2 && stack_b->top != to_a_node)
			rotate_b(stack_b, 1);
		else if (target->index > stack_a->size/2)
			reverse_rotate_a(stack_a, 1);
		else if (to_a_node->index > stack_b->size/2)
			reverse_rotate_b(stack_b, 1);
	}
	push_a(stack_a, stack_b);
}

void	handle(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*smallest;
	//t_node	*to_a_node;
	//int	total_cost;
	//int	smallest_cost;

	while (stack_a->size > 3)
		push_b(stack_a, stack_b);
	sort_three(stack_a);
	find_target(stack_a, stack_b);
	//smallest_cost = 2147483647;
	while (stack_b->top)
	{
		index_list(stack_a);
		index_list(stack_b);
		current = stack_b->top;
		//while (current)
		//{
		//	index_list(stack_a);
		//	index_list(stack_b);
		//	if (current->index == 1)
		//		current->cost_to_top = 0;
		//	else if (current->index == stack_b->size)
		//		current->cost_to_top = 1;
		//	else if (current->index > stack_b->size/2)
		//		current->cost_to_top = stack_b->size - current->index + 1;
		//	else if (current->index < stack_b->size/2)
		//		current->cost_to_top =	current->index - 1;
		//	if (current->target->index == 1)
		//		current->target->cost_to_top = 0;
		//	else if (current->target->index == stack_a->size)
		//		current->target->cost_to_top = 1;
		//	else if (current->target->index > stack_a->size/2)
		//		current->target->cost_to_top = stack_a->size - current->target->index + 1;
		//	else if (current->target->index < stack_a->size/2)
		//		current->target->cost_to_top = current->target->index - 1;
		//	total_cost = current->cost_to_top + current->target->cost_to_top;
		//	if (total_cost < smallest_cost)
		//	{
		//		smallest_cost = total_cost;
		//		to_a_node = current;
		//	}
		//}
		smallest = current;
		while (current)
		{
			if (current->value < smallest->value)
				smallest = current;
			current = current->next;
		}
		move_to_stack_a(smallest, stack_a, stack_b);
	}
	//reverse_rotate_a(stack_a, 1);
	//swap_a(stack_a, 1);
	//rotate_a(stack_a, 1);
	
}
