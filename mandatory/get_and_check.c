/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:03:05 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/24 20:09:39 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get(t_stack *a, int argc, char **argv, t_stack *b)
{
	int		i;
	int		j;
	int		error;
	char	**strs;

	j = 1;
	strs = NULL;
	while (j < argc)
	{
		strs = ft_split(argv[j], ' ');
		if (!strs)
			return (1);
		i = 0;
		while (strs[i])
			ft_lstadd_back(&a->top, ft_lstnew(ft_atoi(strs[i++], \
			&error), a, b, strs));
		free_strs(strs);
		j++;
	}
	a->size = ft_lstsize(a->top);
	a->bottom = ft_lstlast(a->top);
	return (0);
}

int	check_part_2(int strs_len, char **strs)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	while (i < strs_len)
	{
		if (strs[i][0] == 0)
			return (1);
		if (check_invalid_input(strs, strs_len, i))
			return (1);
		if (ft_atoi(strs[i], &error) > 2147483647 \
			|| ft_atoi(strs[i], &error) < -2147483648 \
			|| error == 1)
			return (1);
		j = i + 1;
		while (j < strs_len)
		{
			if (ft_atoi(strs[i], &error) == ft_atoi(strs[j], &error))
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
	int		len;

	j = 1;
	while (j < argc)
	{
		len = 0;
		while (argv[j][len] == 32)
			len++;
		if (argv[j][len] == 0)
			return (1);
		strs = ft_split(argv[j], ' ');
		if (!strs)
			ft_error();
		len = 0;
		while (strs[len])
			len++;
		if (check_part_2(len, strs))
			return (free_strs(strs), 1);
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
