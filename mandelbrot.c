/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 19:50:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/06/08 16:22:10 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	is_colored(double x, double y, t_env env, int i_max)
{
	int	i;
	double	tmp;
	double	z_r;
	double	z_i;

	i = 0;
	z_r = 0;
	z_i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < i_max) 
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + (x / env.zoom + X1);
		z_i = 2 * tmp * z_i + (y / env.zoom + Y1);
		i++;
	}
	if (i == i_max)
		pixel(x, y, 0xFFFFFF, env);
	else
		pixel(x, y, 0x0000FF * i / i_max, env);
}

void		mandelbrot(t_env env)
{
	double		x;
	double		y;

	env.zoom = 500;
	x = 0;
	while (x < env.sx)//(X2 - X1) * env.zoom)
	{
		y = 0;
		while (y < env.sy)//(Y2 - Y1) * env.zoom)
		{
			is_colored(x, y, env, 100);
			y++;
		}
		x++;
	}
	ft_putendl("fin");
}
