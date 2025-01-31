/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_part_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:19:49 by moaatik           #+#    #+#             */
/*   Updated: 2025/01/29 19:22:47 by moaatik          ###   ########.fr       */
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
