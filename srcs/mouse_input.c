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
	if (e->mk->mouse_on == 0)
	{
		if (y >= 0 && y <= W_HEIGHT && x >= 0 && x <= W_LENGHT)
		{
			e->mk->mousex = ((float)x / (W_LENGHT) + -.5 + e->fract_cx) * 2 * e->zoomc[0];
			e->mk->mousey = ((float)y / W_HEIGHT + -.5 + e->fract_cy) * 2 * e->zoomc[1];
			printf("%f_%f\n" ,e->mk->mousex, e->mk->mousey);
			trz(e);
		}
	}
	return (1);
}

int	mousefonct_c(int button, int y, int x, t_e *e)
{
	(void)x;
	(void)y;
	if (button == MOUSE_UP)
	{
		e->zoomc[0] *= 2;
		e->zoomc[1] *= 2;
		e->fract_cx = (e->mk->mousex - e->fract_cx) / 2;
		e->fract_cy = (e->mk->mousey - e->fract_cy) / 2;
		trz(e);
	}
	if (button == MOUSE_DOWN)
	{
		e->zoomc[0] /= 2;
		e->zoomc[1] /= 2;
		e->fract_cx += (e->mk->mousex - e->fract_cx) / 2;
		e->fract_cy += (e->mk->mousey - e->fract_cy) / 2;
		trz(e);
	}
	return (1);
}
