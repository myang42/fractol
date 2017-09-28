/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:59:06 by myang             #+#    #+#             */
/*   Updated: 2017/05/29 18:13:44 by myang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pix_put_img(t_e *e, int y, int x, int color)
{
	int	r;
	int	g;
	int	b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < W_HEIGHT && x < W_LENGHT)
	{
		e->bts[(y * e->img->size_line) + ((e->img->bpp / 8) * x) + 2] = r;
		e->bts[(y * e->img->size_line) + ((e->img->bpp / 8) * x) + 1] = g;
		e->bts[(y * e->img->size_line) + ((e->img->bpp / 8) * x)] = b;
	}
}

void	creat_windows(t_e *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, W_LENGHT, W_HEIGHT, "fractol");
	e->img->img_i = mlx_new_image(e->mlx, W_LENGHT, W_HEIGHT);
	e->bts = mlx_get_data_addr(e->img->img_i, &e->img->bpp,\
			&e->img->size_line, &e->img->endian);
}
