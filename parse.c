/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:55:00 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/23 06:21:45 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_file_height(char *path)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

t_map		parse(char *path)
{
	t_map	m;
	int		fd;
	char	*line;

	m.map = (char ***)malloc(sizeof(char **) * get_file_height(path));
	m.height = 0;
	m.width = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		m.map[m.height] = ft_strsplit(line, ' ');
		m.height++;
		free(line);
	}
	while (m.map[0][m.width])
		m.width++;
	close(fd);
	return (m);
}
