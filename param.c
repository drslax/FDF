/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 06:27:45 by aelouarg          #+#    #+#             */
/*   Updated: 2018/11/23 07:55:51 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_bg(t_window *w, int color)
{
	int		i;
	int		j;

	i = -1;
	while (++i < w->size.h)
	{
		j = -1;
		while (++j < w->size.w)
			mlx_pixel_put(w->mlx_ptr, w->win_ptr, j, i, color);
	}
}

t_point		point(int x, int y)
{
	t_point		p;

	p.x = x;
	p.y = y;
	return (p);
}

t_size		size(int w, int h)
{
	t_size	s;

	s.w = w;
	s.h = h;
	return (s);
}

void		init_params(t_window *w)
{
	w->size.w = 2600;
	w->size.h = 1200;
	w->init.margin = 10;
	w->init.d = 1;
	w->init.s = point(100, 100);
}
