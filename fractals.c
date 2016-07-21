/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 17:31:18 by vroussea          #+#    #+#             */
/*   Updated: 2016/07/21 21:34:22 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractals(double x, double y, t_env env)
{
	if (env->fract == 0)
		mandelbrot(x, y, env);
	if (env->fract == 1)
		julia(x, y, env);
	if (env->fract == 2)
		burning(x, y, env);
	if (env->fract == 3)
		fractal(x, y, env);
}

void		iterate(t_env env)
{
	double	x;
	double	y;

	x = 0;
	env.rat_x = env.x_arc[0];
	while (x < env.sx)
	{
		y = 0;
		env.rat_y = env.y_arc[0];
		while (y < env.sy)
		{
			fractals(x, y, env);
			env.rat_y += (env.y_arc[1] - env.y_arc[0]) / env.sy;
			y++;
		}
		env.rat_x += (env.x_arc[1] - env.x_arc[0]) / env.sx;
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
}
