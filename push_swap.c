/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:29:59 by moaatik           #+#    #+#             */
/*   Updated: 2025/01/29 19:11:03 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_stacknew();
	stack_b = ft_stacknew();
	if (argc < 2 || check_duplicated_numbers(argc, argv))
		ft_error();
	get(stack_a, argc, argv);
	sort_stack(stack_a, stack_b);
	ft_lstclear(stack_a->top);
	free(stack_a);
	ft_lstclear(stack_b->top);
	free(stack_b);
	return (0);
}
