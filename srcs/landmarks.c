/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landmarks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:07:52 by myang             #+#    #+#             */
/*   Updated: 2017/05/30 12:19:38 by myang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	fract_color(t_e *e, int y, int x, int i)
{
	int	color;

	color = 0;
	if (i == e->ite_max)
		color = (e->color->colo == 0) ? 0 : WHITE;
	else
	{
		if (e->color->colo == 0)
			e->color->currentcolor += (PINK_L - e->color->currentcolor);
		else
			e->color->currentcolor += (YELLOW_L + e->color->currentcolor);
		color = (e->color->currentcolor / (e->ite_max - e->color->nbr_ite) * i);
	}
	pix_put_img(e, y, x, color);
}

static void	algo_fract(t_e *e, t_e *z, float cre, float cim)
{
	float	ere;

	ere = z->re;
	if (e->one > -1)
	{
		z->re = (z->re * z->re) - (z->im * z->im) + (cre);
		z->im = (2 * z->im * ere) + (cim);
	}
	else
	{
		z->re = (z->re * z->re) - (z->im * z->im) + (cre);
		z->im = 2 * ABS((z->im * ere)) + (cim);
	}
}

static void	def_c(t_e *e, t_fract *fract, float *cre, float *cim)
{
	if (e->one <= 0)
	{
		*cre = (fract->x / e->zoomc) + fract[0].min;
		*cim = (fract->y / e->zoomc) + fract[1].min;
	}
	else
	{
		*cre = -1.0 * e->mk->valre;
		*cim = -0.667 * e->mk->valim;
	}
}

static void	increasexy(t_e *e, int *x, int *y)
{
	if (*x < (W_LENGHT - (e->mk->mousex / 2)))
		*x += 1;
	else
	{
		*x = -e->mk->mousex / 2;
		*y += 1;
	}
}

void		fractale(t_e *e, t_fract *fract)
{
	t_e	z;
	t_e	c;
	int	i;

	i = 0;
	fract->x = e->mk->mousex / 2;
	fract->y = e->mk->mousey / 2;
	while (fract->y < W_HEIGHT + ((e->mk->mousey / 2)))
	{
		z.re = (e->one <= 0) ? 0 : (fract->x / e->zoomc) + (fract[0].min);
		z.im = (e->one <= 0) ? 0 : (fract->y / e->zoomc) + (fract[1].min);
		def_c(e, fract, &c.re, &c.im);
		while ((z.re * z.re + z.im * z.im) < 4 && i <= e->ite_max - 1)
		{
			algo_fract(e, &z, c.re, c.im);
			i++;
		}
		fract_color(e, fract->y + -e->mk->mousey / 2,
		fract->x + e->mk->mousex / 2, i);
		i = 0;
		increasexy(e, &fract->x, &fract->y);
	}
}
