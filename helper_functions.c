/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:42:32 by moaatik           #+#    #+#             */
/*   Updated: 2025/01/27 16:39:04 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
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
		i++;
	}
	return (result * sign);
}

t_node	*ft_lstfirst(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

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
	int	index;
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

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	i;
	int	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = 0;
	return (ptr);
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


void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
