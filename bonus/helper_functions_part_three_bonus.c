/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_part_three_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:24:05 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/12 18:24:54 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_lstsize(t_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_node *lst)
{
	t_node	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}
