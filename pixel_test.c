/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 16:42:12 by vroussea          #+#    #+#             */
/*   Updated: 2016/07/27 17:23:05 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];

	z[0] = 0;
	z[1] = 0;
	env->pt[0] = env->rat_x / (env->zoom * 250) + env->x1;
	env->pt[1] = env->rat_y / (env->zoom * 250) + env->y1;
	i = 0;
	while (z[0] * z[0] - z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = z[0];
		z[0] = tmp * tmp - z[1] * z[1] + env->pt[0];
		z[1] = 2 * tmp * z[1] + env->pt[1];
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : color(i, env->i_max)), env);
}

void	burning(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];

	z[0] = 0;
	z[1] = 0;
	env->pt[0] = env->rat_x / (env->zoom * 250) + env->x1;
	env->pt[1] = env->rat_y / (env->zoom * 250) + env->y1;
	i = 0;
	while (z[0] * z[0] - z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = absol(z[0]);
		z[0] = tmp * tmp - absol(z[1]) * absol(z[1]) + env->pt[0];
		z[1] = 2 * tmp * absol(z[1]) + env->pt[1];
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : color(i, env->i_max)), env);
}

void	julia(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];

	z[0] = env->rat_x / (env->zoom * 250) + env->x1;
	z[1] = env->rat_y / (env->zoom * 250) + env->y1;
	i = 0;
	while (z[0] * z[0] - z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = z[0];
		z[0] = tmp * tmp - z[1] * z[1] + env->pt[0];
		z[1] = 2 * tmp * z[1] + env->pt[1];
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : color(i, env->i_max)), env);
}

void	fractal(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];

	z[0] = env->rat_x / (env->zoom * 250) + env->x1;
	z[1] = env->rat_y / (env->zoom * 250) + env->y1;
	i = 0;
	while (z[0] * z[0] - z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = absol(z[0]);
		z[0] = tmp * tmp - absol(z[1]) * absol(z[1]) + env->pt[0];
		z[1] = 2 * tmp * absol(z[1]) + env->pt[1];
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : color(i, env->i_max)), env);
}
