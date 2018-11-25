/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 07:22:24 by aelouarg          #+#    #+#             */
/*   Updated: 2018/11/25 07:22:25 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	render_y(t_window *w)
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
		z = w->map[0][j].z;
		sy = w->init.s.y;
		while (++i < w->m.height)
		{
			draw_line(w, w->map[i][j].c, rotate(point(sx, sy), z, w->init.d),
			rotate(point(sx, sy + w->init.margin), w->map[i][j].z, w->init.d));
			z = w->map[i][j].z;
			sy += w->init.margin;
		}
		sx += w->init.margin;
	}
}

static void	render_x(t_window *w)
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
		z = w->map[i][0].z;
		j = -1;
		sx = w->init.s.x;
		while (++j < w->m.width)
		{
			draw_line(w, w->map[i][j].c, rotate(point(sx, sy), z, w->init.d),
			rotate(point(sx + w->init.margin, sy), w->map[i][j].z, w->init.d));
			z = w->map[i][j].z;
			sx += w->init.margin;
		}
		sy += w->init.margin;
	}
}

void		render(t_window *w)
{
	render_x(w);
	render_y(w);
}
