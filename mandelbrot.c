/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 19:50:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/06/09 16:34:01 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void	iterate(double x, double y, t_env env)
{
	int	i;
	double	tmp;
	double	z_r;
	double	z_i;

	z_r = 0;
	z_i = 0;
	env.c_r = x / env.zoom + env.x1;
	env.c_i = y / env.zoom + env.y1;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < env.i_max) 
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + env.c_r;
		z_i = 2 * tmp * z_i + env.c_i;
		i++;
	}
	pixel(x, y, (i == env.i_max ? 
			env.col : env.col * pow(i, -1.001) / env.i_max), env);
}

void		mandelbrot(t_env env)
{
	double		x;
	double		y;

	x = 0;
	while (x < env.sx)
	{
		y = 0;
		while (y < env.sy)
		{
			iterate(x, y, env);
			y++;
		}
		x++;
	}
}
