/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:55:53 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/12 16:44:58 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*remove_content(char *str, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (NULL);
	str = ft_strdup(line + i + 1);
	if (!*str)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

static char	*join_check_search(char **str, char *temp, int bytes, int *stop)
{
	char	*temp1;

	temp1 = NULL;
	if (bytes == 0)
	{
		*stop = 1;
		return (*str);
	}
	temp[bytes] = 0;
	temp1 = *str;
	*str = ft_strjoin(temp1, temp);
	if (!*str)
	{
		free(temp1);
		return (NULL);
	}
	free(temp1);
	if (ft_strchr(temp, '\n'))
	{
		*stop = 1;
		return (*str);
	}
	return (*str);
}

static char	*get_content(int fd, char *temp, char **str)
{
	int		bytes;
	int		stop;

	bytes = 1;
	while (bytes > 0)
	{
		stop = 0;
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(*str);
			*str = NULL;
			return (NULL);
		}
		*str = join_check_search(str, temp, bytes, &stop);
		if (stop == 1)
			break ;
	}
	return (*str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*temp;
	char		*line;
	char		*temp1;
	int			i;

	i = 0;
	temp1 = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	line = get_content(fd, temp, &str);
	free(temp);
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = remove_content(str, line);
	temp1 = line;
	line = ft_substr(temp1, 0, i + 1);
	free(temp1);
	return (line);
}
