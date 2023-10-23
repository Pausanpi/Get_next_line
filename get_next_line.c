/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:06:35 by pausanch          #+#    #+#             */
/*   Updated: 2023/10/23 12:33:12 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *leftstr)
{
	int		bytes;
	char	*buffer;

	if (!leftstr)
		leftstr = ft_challoc(1);
	buffer = ft_challoc(BUFFER_SIZE + 1);
	bytes = 1;
	while (!ft_nlsrch(buffer) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(leftstr), NULL);
		buffer[bytes] = 0;
		leftstr = ft_strjoin(leftstr, buffer);
		if (!leftstr)
			return (free(buffer), free(leftstr), NULL);
	}
	return (free(buffer), leftstr);
}

static char	*ft_line(char *leftstr)
{
	char	*line;
	int		i;

	i = 0;
	if (!leftstr[i])
		return (0);
	while (leftstr[i] && leftstr[i] != '\n')
		i++;
	line = ft_challoc(i + 1 + (leftstr[i] == '\n'));
	i = 0;
	while (leftstr[i] && leftstr[i] != '\n')
	{
		line[i] = leftstr[i];
		i++;
	}
	if (leftstr[i])
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

static char	*ft_next(char *leftstr)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (leftstr[i] && leftstr[i] != '\n')
		i++;
	if (!leftstr[i])
		return (free(leftstr), NULL);
	tmp = ft_challoc(ft_strlen(leftstr) - i);
	i++;
	j = 0;
	while (leftstr[i + j])
	{
		tmp[j] = leftstr[i + j];
		j++;
	}
	tmp[j] = 0;
	return (free(leftstr), tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftstr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, 0, 0) < 0)
	{
		if (leftstr != NULL)
		{
			free(leftstr);
			leftstr = NULL;
		}
		return (NULL);
	}
	leftstr = ft_read(fd, leftstr);
	line = ft_line(leftstr);
	leftstr = ft_next(leftstr);
	return (line);
}
