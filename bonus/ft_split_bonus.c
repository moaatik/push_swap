/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:39:18 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/12 16:44:43 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	count_word(const char *str, char c)
{
	int	inword;
	int	count;
	int	i;

	inword = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (!inword && str[i] != c)
		{
			count++;
			inword = 1;
		}
		else if (inword && str[i] == c)
			inword = 0;
		i++;
	}
	return (count);
}

static void	ft_strcpy(char *ptr, const char *s, int j, int size)
{
	int	i;
	int	x;

	i = 0;
	x = j - size;
	while (i < size)
	{
		ptr[i] = s[x];
		i++;
		x++;
	}
	ptr[i] = 0;
}

static void	get_size(const char *s, char c, int *j, int *size)
{
	while (s[*j] != c && s[*j] != '\0')
	{
		(*j)++;
		(*size)++;
	}
}

static int	ptrcpy(char **ptr, const char *s, char c)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	while (s[j])
	{
		size = 0;
		while (s[j] == c)
			j++;
		if (s[j] == 0)
			break ;
		get_size(s, c, &j, &size);
		ptr[i] = malloc(sizeof(char) * (size + 1));
		if (!ptr[i])
		{
			while (i > 0)
				free (ptr[--i]);
			return (0);
		}
		ft_strcpy(ptr[i], s, j, size);
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		count;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	ptr = malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	if (!ptrcpy(ptr, s, c))
	{
		free (ptr);
		return (NULL);
	}
	ptr[count] = NULL;
	return (ptr);
}
