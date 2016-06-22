/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 18:12:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/06/16 16:56:28 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <mlx.h>

static void		iterate(double x, double y, t_env env)
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
		tmp = absol(z_r);
		z_r = tmp * tmp - absol(z_i) * absol(z_i) + env.c_r;
		z_i = 2 * tmp * absol(z_i) + env.c_i;
		i++;
	}
	pixel(x, y, (i == env.i_max ? 0 : color(i, env.i_max)), env);
}

void			burningship(t_env env)
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

void	burningloop(t_env env)
{
	env.i_max = 70;
	env.x1 = -2.1;
	env.y1 = -1.2;
	burningship(env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 1, 1);
	mlx_hook(env.win, 2, 0, key_funct, &env);
	mlx_hook(env.win, 17, 0, quit_funct, &env);
	mlx_hook(env.win, 4, 0, mouse_burning, &env);
	mlx_loop(env.mlx);
}
