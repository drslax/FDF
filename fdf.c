/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 21:35:07 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/23 20:47:03 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		press(int btn, int x, int y, void *param)
{
	static int	x0 = -1;
	static int	y0 = -1;

	if (x >= 0 && y >= 0 && btn == 1)
	{
		if (x0 < 0 && y0 < 0)
		{
			x0 = x;
			y0 = y;
		}
		else
		{
			draw_line((t_window *)param, 0xff0000, point(x0, y0), point(x, y));
			x0 = -1;
			y0 = -1;
		}
	}
	if (btn == 2)
	{
		x0 = -1;
		y0 = -1;
	}
	return (1);
}

void	render_y(t_window *w)
{
	int			i;
	int			j;
	int			z;
	double		sx;
	double		sy;

	j = -1;
	sx = w->init.s.x + w->init.margin;
	while (++j < w->m.width)
	{
		i = -1;
		z = 0;
		sy = w->init.s.y;
		while (++i < w->m.height)
		{
			draw_line(w, GREEN, rotate(point(sx, sy), z, w->init.d),
			rotate(point(sx, sy + w->init.margin), w->map[i][j].z, w->init.d));
			z = w->map[i][j].z;
			sy += w->init.margin;
		}
		sx += w->init.margin;
	}
	draw_line(w, GREEN, rotate(point(w->init.s.x, w->init.s.y), z, w->init.d),
	rotate(point(w->init.s.x, sy), z, w->init.d));
}

void	render_x(t_window *w)
{
	int			i;
	int			j;
	int			z;
	double		sx;
	double		sy;

	i = -1;
	sy = w->init.s.y + w->init.margin;
	while (++i < w->m.height)
	{
		z = 0;
		j = -1;
		sx = w->init.s.x;
		while (++j < w->m.width)
		{
			draw_line(w, GREEN, rotate(point(sx, sy), z, w->init.d),
			rotate(point(sx + w->init.margin, sy), w->map[i][j].z, w->init.d));
			z = w->map[i][j].z;
			sx += w->init.margin;
		}
		sy += w->init.margin;
	}
	draw_line(w, GREEN, rotate(point(sx, w->init.s.y), z, w->init.d),
	rotate(point(w->init.s.x, w->init.s.y), 0, w->init.d));
}

void    render(t_window *w)
{
	render_x(w);
	render_y(w);
}

int		zoom(int keycode, void *param)
{
	if (keycode == 0x35)
		exit(1);
	else if (keycode == 0x45)
		((t_window *)param)->init.margin += 10;
	else if (keycode == 0x4e && ((t_window *)param)->init.margin - 10 > 0)
		((t_window *)param)->init.margin -= 10;
	else if (keycode == 0x7d)
		((t_window *)param)->init.s.y += 50;
	else if (keycode == 0x7e)
		((t_window *)param)->init.s.y -= 50;
	else if (keycode == 0x7c)
		((t_window *)param)->init.s.x += 50;
	else if (keycode == 0x7b)
		((t_window *)param)->init.s.x -= 50;
	else if (keycode == 0x02)
		((t_window *)param)->init.d--;
	else if (keycode == 0x20)
		((t_window *)param)->init.d++;
	else if (keycode == 0x31)
		init_params((t_window *)param);
	mlx_clear_window(((t_window *)param)->mlx_ptr,
			((t_window *)param)->win_ptr);
	ft_string_put((t_window *)param);
	render((t_window *)param);
	return (1);
}

t_coord	**create_map(t_window *w)
{
	int			i;
	int			j;
	char		*c;
	t_coord		**map;

	i = -1;
	map = (t_coord **)malloc(sizeof(t_coord *) * w->m.height);
	while (++i < w->m.height)
	{
		j = -1;
		map[i] = (t_coord *)malloc(sizeof(t_coord) * w->m.width);
		while (++j < w->m.width)
		{
			map[i][j].z = ft_atoi(w->m.map[i][j]);
			if ((c = ft_strchr(w->m.map[i][j], 'x')) != NULL)
			{
				c = ft_strupcase(c + 1);
				map[i][j].c = ft_basetoi(c, "0123456789ABCDEF");
			}
			else
				map[i][j].c = WHITE;
		}
	}
	return (map);
}
