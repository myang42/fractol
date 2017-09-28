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
			e->mk->valre = (float)x / (float)W_HEIGHT;
			e->mk->valim = (float)y / (float)W_LENGHT;
			trz(e);
		}
	}
	return (1);
}

int	mousefonct_c(int button, int y, int x, t_e *e)
{
	float	x2;
	float	y2;

	y2 = ((float)x - W_HEIGHT / 2);
	x2 = ((float)y - W_LENGHT / 2);
	if (button == MOUSE_UP)
		e->zoomc += 100;
	if (button == MOUSE_DOWN)
		e->zoomc += (e->zoomc > 100) ? -100 : 0;
	while (y2 != 0)
	{
		e->mk->mousey -= (y2 > 0) ? -1 : 1;
		y2 += (y2 > 0) ? -0.5 : 0.5;
	}
	while (x2 != 0)
	{
		e->mk->mousex += (x2 > 0) ? -1 : 1;
		x2 += (x2 > 0) ? -0.5 : 0.5;
	}
	trz(e);
	return (1);
}
