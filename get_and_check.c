/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:03:05 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/01 15:22:17 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get(t_stack *a, int argc, char **argv)
{
	int		i;
	char	**strs;
	t_node	*node;

	i = 1;
	strs = NULL;
	node = NULL;
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		i = 0;
		while (strs[i])
			ft_lstadd_back(&node, ft_lstnew(ft_atoi(strs[i++])));
	}
	else
	{
		while (i < argc)
			ft_lstadd_back(&node, ft_lstnew(ft_atoi(argv[i++])));
	}
	a->top = node;
	a->size = ft_lstsize(node);
	a->bottom = ft_lstlast(node);
	free_strs(strs);
}

int	check_part_2(int strs_len, char **strs, int i, int j)
{
	while (i < strs_len)
	{
		if (ft_atoi(strs[i]) > 2147483647 || ft_atoi(strs[i]) < -2147483648)
			return (1);
		j = i + 1;
		while (j < strs_len)
		{
			if (ft_atoi(strs[i]) == ft_atoi(strs[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_range_and_duplicated_numbers(int argc, char **argv)
{
	int		i;
	int		j;
	char	**strs;
	int		strs_len;
	int		retrun_value;

	j = 0;
	i = 1;
	strs_len = argc;
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		i = 0;
		strs_len = 0;
		while (strs[strs_len])
			strs_len++;
	}
	else
		strs = argv;
	retrun_value = check_part_2(strs_len, strs, i, j);
	if (argc == 2)
		free_strs(strs);
	return (retrun_value);
}

int	already_sorted(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstclear((*stack_a)->top);
	free(*stack_a);
	ft_lstclear((*stack_b)->top);
	free(*stack_b);
}
