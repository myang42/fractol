/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:13:18 by myang             #+#    #+#             */
/*   Updated: 2017/05/30 12:24:02 by myang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_error(t_e *e)
{
	ft_putstr_fd("\nOnly\n\033[1;31mMANDELBROT\n\
JULIA\nBURNINGSHIP\n\033[0mAre Allowed.\n\n", 2);
	free_val(e);
}
