/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 18:12:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/07/17 16:31:24 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <mlx.h>

static void		iterate(double x, double y, t_env env)
{
	int	i;
	double	tmp;
	double	z[2];

	z[0] = 0;
	z[1] = 0;
	env.pt[0] = x / env.zoom + env.x1;
	env.pt[1] = y / env.zoom + env.y1;
	i = 0;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env.i_max) 
	{
		tmp = absol(z[0]);
		z[0] = tmp * tmp - absol(z[1]) * absol(z[1]) + env.pt[0];
		z[1] = 2 * tmp * absol(z[1]) + env.pt[1];
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