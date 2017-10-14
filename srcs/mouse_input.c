/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 18:22:28 by myang             #+#    #+#             */
/*   Updated: 2017/05/30 12:26:13 by myang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mousefonct(int x, int y, t_e *e)
{
	if (y >= 0 && y <= W_HEIGHT && x >= 0 && x <= W_LENGHT)
	{
		e->mk->mousex = ((float)x / W_LENGHT + -.5) * 2 * e->zoomc[0] +
		e->fract_cx;
		e->mk->mousey = ((float)y / W_HEIGHT + -.5) * 2 * e->zoomc[1] +
		e->fract_cy;
		trz(e);
	}
	return (1);
}

int	mousefonct_c(int button, int y, int x, t_e *e)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT && e->zoomc[1] <= 1000)
	{
		e->zoomc[0] *= 2.0;
		e->zoomc[1] *= 2.0;
		e->fract_cx -= ((e->mk->mousex - e->fract_cx) / 2.0) / 0.5;
		e->fract_cy -= ((e->mk->mousey - e->fract_cy) / 2.0) / 0.5;
		trz(e);
	}
	if (button == MOUSE_RIGHT)
	{
		e->zoomc[0] /= 2.0;
		e->zoomc[1] /= 2.0;
		e->fract_cx += (e->mk->mousex - e->fract_cx) / 2.0;
		e->fract_cy += (e->mk->mousey - e->fract_cy) / 2.0;
		trz(e);
	}
	return (1);
}
