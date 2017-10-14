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
		color = (e->color->currentcolor / (e->ite_max) * i);
	}
	pix_put_img(e, y, x, color);
}

static void	algo_fract(t_e *e, t_e *z)
{
	float	ere;

	ere = z->re;
	if (e->one > -1)
	{
		z->re = (z->re * z->re) - (z->im * z->im) + e->re;
		z->im = (2 * z->im * ere) + e->im;
	}
	else
	{
		z->re = (z->re * z->re) - (z->im * z->im) + e->re;
		z->im = 2 * ABS((z->im * ere)) + e->im;
	}
}

static void	increasexy(int *x, int *y)
{
	if (*x < (W_LENGHT))
		*x += 1;
	else
	{
		*x = 0;
		*y += 1;
	}
}

void		fractale(t_e *e, t_fract *fract)
{
	t_e	z;
	int	i;

	fract->x = 0;
	fract->y = 0;
	while (fract->y < W_HEIGHT)
	{
		i = 0;
		e->val->x = ((float)fract->x / (W_LENGHT) + -.5) * 2 * e->zoomc[0] +
		e->fract_cx;
		e->val->y = ((float)fract->y / W_HEIGHT + -.5) * 2 * e->zoomc[1] +
		e->fract_cy;
		e->re = (e->one != 1) ? e->val->x : e->mk->mousex;
		e->im = (e->one != 1) ? e->val->y : e->mk->mousey;
		z.re = (e->one != 1) ? 0 : e->val->x;
		z.im = (e->one != 1) ? 0 : e->val->y;
		while ((z.re * z.re + z.im * z.im) < 4 && i <= e->ite_max - 1)
		{
			algo_fract(e, &z);
			i++;
		}
		fract_color(e, fract->y, fract->x, i);
		increasexy(&fract->x, &fract->y);
	}
}
