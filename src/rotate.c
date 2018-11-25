/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 07:22:37 by aelouarg          #+#    #+#             */
/*   Updated: 2018/11/25 07:22:38 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point		mirror(t_point p, int x)
{
	t_point pp;

	pp.x = 2 * x - p.x;
	pp.y = p.y;
	return (pp);
}

t_point		rotate(t_point p, int z, int depth)
{
	t_point	pp;
	double	tata;

	tata = 60;
	p.x -= 600;
	p.y -= 600;
	pp.x = 600 + p.x * cos(tata) - p.y * sin(tata - 90);
	pp.y = 600 + p.x * sin(tata) + p.y * cos(tata - 90) - z * depth;
	return (mirror(pp, 900));
}
