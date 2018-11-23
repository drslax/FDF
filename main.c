/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 06:56:31 by aelouarg          #+#    #+#             */
/*   Updated: 2018/11/23 20:36:51 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_string_put(t_window *fdf)
{
	mlx_string_put(fdf->mlx_ptr,
			fdf->win_ptr, 30, 50, 0x83E4BC, "U & D : HEIGHT");
	mlx_string_put(fdf->mlx_ptr,
			fdf->win_ptr, 19, 110, 0x83E4BC, "+ & -  : ZOOM");
	mlx_string_put(fdf->mlx_ptr,
			fdf->win_ptr, 9, 70, 0x83E4BC, "<- & -> : L & R");
	mlx_string_put(fdf->mlx_ptr,
			fdf->win_ptr, 9, 90, 0x83E4BC, "UP & DW : U & D");
	mlx_string_put(fdf->mlx_ptr,
			fdf->win_ptr, 30, 30, 0x83E4BC, "SPACE :  RESET");
}

int		main(int ac, char **av)
{
	int			i;
	int			j;
	t_window	w;
	t_map		m;
	t_coord		**map;

	if (ac == 2)
	{
		init_params(&w);
		w.mlx_ptr = mlx_init();
		w.win_ptr = mlx_new_window(w.mlx_ptr, w.size.w, w.size.h, "FDF");
		w.m = parse(av[1]);
		w.map = create_map(&w);
		render_y(&w);
		render_x(&w);
		mlx_key_hook(w.win_ptr, zoom, (void *)&w);
		mlx_mouse_hook(w.win_ptr, press, (void *)&w);
		ft_string_put(&w);
		mlx_loop(w.mlx_ptr);
	}
	return (0);
}
