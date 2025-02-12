/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_part_two_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:19:49 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/12 18:24:45 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstclear((*stack_a)->top);
	free(*stack_a);
	ft_lstclear((*stack_b)->top);
	free(*stack_b);
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

void	manage_size_and_print(t_stack *up, t_stack *down, int print, char c)
{
	if (print && c == 'a')
		write(1, "pa\n", 3);
	else if (print && c == 'b')
		write(1, "pb\n", 3);
	up->size++;
	down->size--;
}
