/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_functions_part_2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:55:10 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/08 16:58:58 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *values, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] > values[j])
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_median(t_stack *stack)
{
	int		*values;
	int		median;
	int		i;
	t_node	*current;

	values = malloc(stack->size * sizeof(int));
	if (!values)
		return (0);
	current = stack->top;
	i = 0;
	while (current)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
	sort_array(values, stack->size);
	median = values[stack->size / 2];
	free(values);
	return (median);
}

void	push_to_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int	median;

	median = find_median(stack_a);
	while (stack_a->size > 5)
	{
		push_b(stack_a, stack_b, 1);
		if (stack_b->top->value > median)
			rotate_b(stack_b, 1);
	}
}

void	sort_three(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value && \
		stack->top->value > stack->bottom->value)
		rotate_a(stack, 1);
	if (stack->top->value > stack->top->next->value)
		swap_a(stack, 1);
	if (stack->top->next->value > stack->bottom->value)
		reverse_rotate_a(stack, 1);
	if (stack->top->value > stack->top->next->value)
		swap_a(stack, 1);
}

void	index_list(t_stack *stack)
{
	int		index;
	t_node	*current;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	index = 1;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}
