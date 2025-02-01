/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:29:59 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/01 15:23:33 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_stacknew();
	stack_b = ft_stacknew();
	if (argc < 2)
		return (0);
	if (check_range_and_duplicated_numbers(argc, argv))
		ft_error();
	get(stack_a, argc, argv);
	if (!already_sorted(stack_a))
	{
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
