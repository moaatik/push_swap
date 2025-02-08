/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_part_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:19:49 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/08 16:58:06 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
			if (strs[i][j] < '0' || strs[i][j] > '9')
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

t_node	*ft_lstnew(int value)
{
	t_node	*new_list;

	new_list = malloc(sizeof(t_node));
	if (!new_list)
		return (NULL);
	new_list->value = value;
	new_list->next = NULL;
	new_list->prev = NULL;
	return (new_list);
}
