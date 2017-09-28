/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:53:58 by myang             #+#    #+#             */
/*   Updated: 2017/09/17 16:59:59 by myang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include "./pxl_color.h"
# include "./keys.h"

# define W_LENGHT 860
# define W_HEIGHT 640

typedef struct	s_fract
{
	float		min;
	float		max;
	int			x;
	int			y;
}				t_fract;

typedef struct	s_img
{
	void		*img_i;
	int			bpp;
	int			endian;
	int			size_line;
}				t_img;

typedef struct	s_color
{
	int			nbr_ite;
	int			colo;
	int			currentcolor;
}				t_color;

typedef struct	s_mk
{
	int			mousex;
	int			mousey;
	int			mouse_on;
	int			key;
	float		valre;
	float		valim;
}				t_mk;

typedef struct	s_e
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_color		*color;
	t_mk		*mk;
	t_fract		*fract;
	char		*bts;
	float		zoomc;
	float		im;
	float		re;
	int			ite_max;
	int			one;
}				t_e;

void			p_plan(t_e *e, t_fract *fract);
void			fractale(t_e *e, t_fract *fract);
void			pix_put_img(t_e *e, int y, int x, int z);
void			creat_windows(t_e *e);
void			init_var(t_e *e);
void			init_struct(t_e *e);
void			keyfonc_c(t_e *e);
void			trz(t_e *e);
void			print_error(t_e *e);
void			free_val(t_e *e);
int				the_one_is(t_e *e, t_fract *fract, char *name);
int				keyfonc(int key, t_e *e);
int				mousefonct(int x, int y, t_e *e);
int				mousefonct_c(int button, int x, int y, t_e *e);
int				main(int argv, char **argc);

#endif
