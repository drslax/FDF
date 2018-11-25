/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 07:22:12 by aelouarg          #+#    #+#             */
/*   Updated: 2018/11/25 07:22:14 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

static void	check_error(t_map *m)
{
	int i;
	int j;

	i = 0;
	while (++i < m->height)
	{
		j = -1;
		while (m->map[i][++j])
			;
		if (j != m->width)
			m->err = 1;
	}
}

t_map		parse(char *path)
{
	t_map	m;
	int		fd;
	char	*line;

	m.err = 0;
	m.width = 0;
	m.height = 0;
	fd = open(path, O_RDONLY);
	m.map = (char ***)malloc(sizeof(char **) * get_file_height(path));
	while (get_next_line(fd, &line) > 0)
	{
		m.map[m.height] = ft_strsplit(line, ' ');
		m.height++;
		free(line);
	}
	if (m.height > 0 && m.height < 501)
	{
		while (m.map[0][m.width])
			m.width++;
		check_error(&m);
	}
	else
		m.err = 1;
	close(fd);
	return (m);
}
