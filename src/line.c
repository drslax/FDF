/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 07:21:36 by aelouarg          #+#    #+#             */
/*   Updated: 2018/11/25 07:21:37 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

static void	draw_line_high(t_window *w, int color, t_point p0, t_point p1)
{
	int dx;
	int dy;
	int dd;
	int xi;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	dd = 2 * dx - dy;
	while (p0.y <= p1.y)
	{
		mlx_pixel_put(w->mlx_ptr, w->win_ptr, p0.x, p0.y, color);
		if (dd > 0)
		{
			p0.x += xi;
			dd -= (2 * dy);
		}
		dd += (2 * dx);
		p0.y++;
	}
}

static void	draw_line_low(t_window *w, int color, t_point p0, t_point p1)
{
	int dx;
	int dy;
	int dd;
	int yi;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	dd = 2 * dy - dx;
	while (p0.x <= p1.x)
	{
		mlx_pixel_put(w->mlx_ptr, w->win_ptr, p0.x, p0.y, color);
		if (dd > 0)
		{
			p0.y += yi;
			dd -= (2 * dx);
		}
		dd += (2 * dy);
		p0.x++;
	}
}

void		draw_line(t_window *w, int color, t_point p0, t_point p1)
{
	if (ft_abs(p1.y - p0.y) < ft_abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			draw_line_low(w, color, p1, p0);
		else
			draw_line_low(w, color, p0, p1);
	}
	else
	{
		if (p0.y > p1.y)
			draw_line_high(w, color, p1, p0);
		else
			draw_line_high(w, color, p0, p1);
	}
}
