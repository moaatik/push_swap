/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:03:05 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/12 16:44:53 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	get(t_stack *a, int argc, char **argv, t_stack *b)
{
	int		i;
	int		j;
	char	**strs;
	t_node	*node;

	j = 1;
	strs = NULL;
	node = NULL;
	while (j < argc)
	{
		strs = ft_split(argv[j], ' ');
		if (!strs)
			ft_error();
		i = 0;
		while (strs[i])
			ft_lstadd_back(&node, ft_lstnew(ft_atoi(strs[i++]), a, b, strs));
		free_strs(strs);
		j++;
	}
	a->top = node;
	a->size = ft_lstsize(node);
	a->bottom = ft_lstlast(node);
}

int	check_part_2(int strs_len, char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (i < strs_len)
	{
		if (strs[i][0] == 0)
			return (1);
		if (check_invalid_input(strs, strs_len, i))
			return (1);
		if (ft_atoi(strs[i]) > 2147483647 || ft_atoi(strs[i]) < -2147483648 \
			|| ft_strlen(strs[i]) > 11)
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
	int		j;
	char	**strs;
	int		strs_len;

	j = 1;
	while (j < argc)
	{
		strs = ft_split(argv[j], ' ');
		if (!strs)
			ft_error();
		strs_len = 0;
		while (strs[strs_len])
			strs_len++;
		if (check_part_2(strs_len, strs))
		{
			free_strs(strs);
			return (1);
		}
		free_strs(strs);
		j++;
	}
	return (0);
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

int	check_duplicate_in_stack(t_stack *stack_a)
{
	t_node	*current;
	t_node	*temp;

	current = stack_a->top;
	temp = current;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->value == temp->value)
				return (1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}
