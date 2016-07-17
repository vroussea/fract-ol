/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 21:28:33 by vroussea          #+#    #+#             */
/*   Updated: 2016/07/17 16:33:20 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static void	iterate(double x, double y, t_env env)
{
	int		i;
	double	tmp;
	double	z[2];

	z[0] = x / env.zoom + env.x1;
	z[1] = y / env.zoom + env.y1;
	i = 0;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env.i_max)
	{
		tmp = absol(z[0]);
		z[0] = tmp * tmp - absol(z[1]) * absol(z[1]) + env.pt[0];
		z[1] = 2 * absol(z[1]) * tmp + env.pt[1];
		i++;
	}
	pixel(x, y, (i == env.i_max ? 0 : color(i, env.i_max)), env);
}

void		fract(t_env env)
{
	double	x;
	double	y;

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

void	fractloop(t_env env)
{
	env.i_max = 50;
	env.x1 = -1.5;
	env.y1 = -1.5;
	env.pt[0] = 0.285;
	env.pt[1] = 0.01;
	julia(env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 1, 1);
	mlx_hook(env.win, 2, 0, key_funct, &env);
	mlx_hook(env.win, 17, 0, quit_funct, &env);
	//mlx_hook(env.win, 6, 0, move_fract, &env);
	mlx_loop(env.mlx);
}
