/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_part_three_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:24:05 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/14 19:35:22 by moaatik          ###   ########.fr       */
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

t_instruction	*ft_lstnew_instruction(char *str, t_stack *stack_a, \
	t_stack *stack_b, t_instruction *instructions)
{
	t_instruction	*new_instruction;

	new_instruction = malloc(sizeof(t_instruction));
	if (!new_instruction)
	{
		free_stacks(&stack_a, &stack_b);
		free_instructions(instructions);
		ft_error();
	}
	new_instruction->instruction = str;
	new_instruction->next = NULL;
	return (new_instruction);
}

void	ft_lstadd_back_instruction(t_instruction **lst, t_instruction *new)
{
	t_instruction	*last_nod;

	if (!lst || !new)
		return ;
	last_nod = *lst;
	if (last_nod == NULL)
	{
		*lst = new;
		return ;
	}
	while (last_nod->next)
		last_nod = last_nod->next;
	last_nod -> next = new;
}
