/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:29:59 by moaatik           #+#    #+#             */
/*   Updated: 2025/01/28 18:10:59 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void f(){system("leaks a.out");}

#include <stdio.h>
int	main(int argc, char **argv)
{
	//atexit(f);
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_stacknew();
	stack_b = ft_stacknew();
	if (argc < 2 || check_duplicated_numbers(argc, argv))
		ft_error();
	get(stack_a, argc, argv);

	handle(stack_a, stack_b);
	
	t_node	*tmp;
	tmp = ft_lstfirst(stack_a->top);
	while (tmp)
	{
		printf("value: %d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_lstclear(stack_a->top);
	free(stack_a);
	ft_lstclear(stack_b->top);
	free(stack_b);
	return (0);
}
