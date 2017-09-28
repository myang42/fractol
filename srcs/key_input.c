/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:28:29 by myang             #+#    #+#             */
/*   Updated: 2017/05/30 12:23:07 by myang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	reset_img(t_e *e)
{
	mlx_clear_window(e->mlx, e->win);
	ft_bzero(e->bts, ft_strlen(e->bts));
	mlx_destroy_image(e->mlx, e->img->img_i);
	e->img->img_i = mlx_new_image(e->mlx, W_LENGHT, W_HEIGHT);
	e->bts = mlx_get_data_addr(e->img->img_i,\
			&e->img->bpp, &e->img->size_line, &e->img->endian);
}

void		trz(t_e *e)
{
	reset_img(e);
	fractale(e, e->fract);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img_i, 0, 0);
}

void		keyfonc_c(t_e *e)
{
	if (e->mk->key == KEY_DOWN)
		e->mk->mousey += 10;
	if (e->mk->key == KEY_UP)
		e->mk->mousey -= 10;
	if (e->mk->key == KEY_RIGHT)
		e->mk->mousex -= 10;
	if (e->mk->key == KEY_LEFT)
		e->mk->mousex += 10;
	if (e->mk->key == KEY_MINUS && e->color->nbr_ite < (e->ite_max - 10))
		e->color->nbr_ite += 1;
	if (e->mk->key == KEY_PLUS && e->color->nbr_ite > 0)
		e->color->nbr_ite -= 1;
	trz(e);
}

int			keyfonc(int key, t_e *e)
{
	e->mk->key = key;
	if (key == KEY_C)
	{
		e->color->colo = (e->color->colo == 0) ? 1 : 0;
		trz(e);
	}
	if (key == KEY_X)
		e->mk->mouse_on = (e->mk->mouse_on != 1) ? 1 : 0;
	if (key == KEY_PLUS || key == KEY_MINUS)
		keyfonc_c(e);
	if (key == KEY_UP || key == KEY_DOWN ||
		key == KEY_RIGHT || key == KEY_LEFT)
		keyfonc_c(e);
	if (key == KEY_O)
	{
		init_var(e);
		trz(e);
	}
	if (key == KEY_ESC)
		exit(EXIT_FAILURE);
	return (1);
}
