/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:27:36 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/24 21:09:25 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

long	ft_atoi(const char *str, int *error)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	*error = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			return (*error = 1, result * sign);
		i++;
	}
	return (result * sign);
}

int	check_invalid_input(char **strs, int strs_len, int i)
{
	int	j;

	while (i < strs_len)
	{
		j = 0;
		if (strs[i][j] == '\0')
			return (1);
		if (strs[i][j] == '+' || strs[i][j] == '-')
		{
			j++;
			if (!strs[i][j])
				return (1);
		}
		while (strs[i][j])
		{
			if ((strs[i][j] < '0' || strs[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last_nod;

	if (!lst || !new)
		return ;
	last_nod = ft_lstlast(*lst);
	if (last_nod == NULL)
		*lst = new;
	else
	{
		last_nod -> next = new;
		new -> prev = last_nod;
	}
}

t_stack	*ft_stacknew(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->size = 0;
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	return (new_stack);
}

t_node	*ft_lstnew(int value, t_stack *a, t_stack *b, char **strs)
{
	t_node	*new_list;

	new_list = malloc(sizeof(t_node));
	if (!new_list)
	{
		free_strs(strs);
		free_stacks(&a, &b);
		ft_error();
	}
	new_list->value = value;
	new_list->next = NULL;
	new_list->prev = NULL;
	return (new_list);
}
