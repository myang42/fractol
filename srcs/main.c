/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:28:30 by myang             #+#    #+#             */
/*   Updated: 2017/07/03 16:02:53 by myang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		p_plan(t_e *e, t_fract *fract)
{
	e->ite_max = 25;
	fractale(e, fract);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img_i, 0, 0);
}

static void	free_mlx(t_e *e)
{
	free(e->mlx);
	free(e->win);
	ft_bzero(e->bts, ft_strlen(e->bts));
	free(e->bts);
}

int			main(int argv, char **argc)
{
	t_e		e;

	init_struct(&e);
	if (argv != 2)
	{
		print_error(&e);
		exit(EXIT_FAILURE);
	}
	if (the_one_is(&e, argc[1]) == 0)
	{
		print_error(&e);
		exit(EXIT_FAILURE);
	}
	creat_windows(&e);
	p_plan(&e, e.fract);
	mlx_key_hook(e.win, &keyfonc, &e);
	mlx_mouse_hook(e.win, &mousefonct_c, &e);
	mlx_hook(e.win, 6, 1L << 6, &mousefonct, &e);
	mlx_loop(e.mlx);
	free_mlx(&e);
	free_val(&e);
	return (0);
}
