/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 07:21:59 by aelouarg          #+#    #+#             */
/*   Updated: 2018/11/25 07:22:00 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
	w->size.w = 1920;
	w->size.h = 1080;
	w->init.margin = 10;
	w->init.d = w->init.margin / 5;
	w->init.s = point(100, 100);
}
