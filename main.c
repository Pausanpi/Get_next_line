/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:52:57 by pausanch          #+#    #+#             */
/*   Updated: 2023/10/20 12:38:28 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("texto.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("p1: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("p2: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("p3: %s", str);
	free(str);
	close(fd);
	return (0);
}