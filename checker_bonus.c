/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:06:17 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/07 19:38:08 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_move(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (!(ft_strcmp(str, "sa\n")))
		swap_a(stack_a, 0);
	else if (!(ft_strcmp(str, "sb\n")))
		swap_b(stack_b, 0);
	else if (!(ft_strcmp(str, "ss\n")))
		swap_a_and_b(stack_a, stack_b, 0);
	else if (!(ft_strcmp(str, "pa\n")))
		push_a(stack_a, stack_b, 0);
	else if (!(ft_strcmp(str, "pb\n")))
		push_b(stack_a, stack_b, 0);
	else if (!(ft_strcmp(str, "ra\n")))
		rotate_a(stack_a, 0);
	else if (!(ft_strcmp(str, "rb\n")))
		rotate_b(stack_b, 0);
	else if (!(ft_strcmp(str, "rr\n")))
		rotate_a_and_b(stack_a, stack_b, 0);
	else if (!(ft_strcmp(str, "rra\n")))
		reverse_rotate_a(stack_a, 0);
	else if (!(ft_strcmp(str, "rrb\n")))
		reverse_rotate_b(stack_b, 0);
	else if (!(ft_strcmp(str, "rrr\n")))
		reverse_rotate_a_and_b(stack_a, stack_b, 0);
	else
		return (1);
	return (0);
}

void	checker_sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	char	*str;
	int		original_size;

	original_size = stack_a->size;
	str = get_next_line(0);
	while (str)
	{
		if (check_move(str, stack_a, stack_b))
		{
			free(str);
			write(2, "Error\n", 6);
			return ;
		}
		free(str);
		str = get_next_line(0);
	}
	if (!already_sorted(stack_a) && stack_b->size == 0 && \
		stack_a->size == original_size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_stacknew();
	stack_b = ft_stacknew();
	if (argc < 2)
		return (0);
	if (argv[1][0] == 0 || check_range_and_duplicated_numbers(argc, argv))
		ft_error();
	get(stack_a, argc, argv);
	checker_sort_stack(stack_a, stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
