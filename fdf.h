/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 01:46:31 by onahiz            #+#    #+#             */
/*   Updated: 2018/11/23 20:34:51 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# define RED 0xff0000
# define BLUE 0x0000ff
# define GREEN 0x00ff00
# define WHITE 0xffffff
# define BLACK 0x000000
# define GREY 0x202020

typedef struct	s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct	s_param
{
	int		margin;
	int		d;
	t_point	s;
}				t_param;

typedef struct	s_map
{
	char	***map;
	int		height;
	int		width;
}				t_map;

typedef struct	s_coord
{
	int		z;
	int		c;
}				t_coord;

typedef struct	s_size
{
	int		w;
	int		h;
}				t_size;

typedef struct	s_window
{
	void	*win_ptr;
	void	*mlx_ptr;
	t_map	m;
	t_param init;
	t_coord **map;
	t_size	size;
}				t_window;

void			ft_string_put(t_window *fdf);
int				press(int btn, int x, int y, void *param);
t_coord			**create_map(t_window *w);
int				zoom(int keycode, void *param);
void			render_y(t_window *w);
void			render_x(t_window *w);
void			put_bg(t_window *w, int color);
t_point			point(int x, int y);
t_size			size(int w, int h);
void			init_params(t_window *w);
t_point			rotate(t_point p, int z, int d);
t_map			parse(char *path);
int				ft_abs(int value);
void			draw_line(t_window *w, int color, t_point p0, t_point p1);

#endif
