/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:43:31 by myang             #+#    #+#             */
/*   Updated: 2017/05/30 12:25:17 by myang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	which_one(char *name)
{
	int	numero;

	numero = 666;
	name = ft_all_upper(name);
	if (ft_strcmp(name, "MANDELBROT") == 0)
		numero = 0;
	if (ft_strcmp(name, "JULIA") == 0)
		numero = 1;
	if (ft_strcmp(name, "BURNINGSHIP") == 0)
		numero = -1;
	return (numero);
}

int			the_one_is(t_e *e, t_fract *fract, char *name)
{
	e->one = which_one(name);
	if (e->one == 1)
	{
		fract[0].min = -1.0;
		fract[0].max = 1.0;
		fract[1].min = -1.2;
		fract[1].max = 1.2;
	}
	if (e->one == -1)
	{
		fract[0].min = -2;
		fract[0].max = 0;
		fract[1].min = -2;
		fract[1].max = 0;
	}
	if (e->one == 0)
	{
		fract[0].min = -2.1;
		fract[0].max = 0.6;
		fract[1].min = -1.2;
		fract[1].max = 1.2;
	}
	return ((e->one == 666) ? 0 : 1);
}

void		init_var(t_e *e)
{
	e->color->colo = 0;
	e->color->nbr_ite = 0;
	e->color->currentcolor = 0;
	e->zoomc = 100;
	e->mk->mousey = -W_HEIGHT + W_HEIGHT / 3;
	e->mk->mousex = W_LENGHT - W_LENGHT / 4;
	e->mk->valre = 1;
	e->mk->valim = 1;
}

void		init_struct(t_e *e)
{
	e->img = (t_img*)malloc(sizeof(t_img));
	e->color = (t_color*)malloc(sizeof(t_color));
	e->fract = (t_fract*)malloc(sizeof(t_fract) * 2);
	e->mk = (t_mk*)malloc(sizeof(t_mk) * 2);
	init_var(e);
}

void		free_val(t_e *e)
{
	free(e->color);
	free(e->mk);
	free(e->img);
	free(e->fract);
}
