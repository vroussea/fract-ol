/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 16:42:12 by vroussea          #+#    #+#             */
/*   Updated: 2016/08/16 19:54:29 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];
	int		col;

	z[0] = 0;
	z[1] = 0;
	env->pt[0] = (x - env->sx / 2) / env->zoom + env->move[0];
	env->pt[1] = (y - env->sy / 2) / env->zoom + env->move[1];
	i = 0;
	col = 0x00FFFFFF;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = z[0];
		z[0] = tmp * tmp - z[1] * z[1] + env->pt[0];
		z[1] = 2 * tmp * z[1] + env->pt[1];
		col -= env->colmod;
		if (col < 0)
			col = 0x00FFFFFF;
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : col), env);
}

void	burning(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];
	int		col;

	z[0] = 0;
	z[1] = 0;
	env->pt[0] = env->rat_x / env->zoom + env->x1 + env->move[0];
	env->pt[1] = env->rat_y / env->zoom + env->y1 + env->move[1];
	i = 0;
	col = 0x00FFFFFF;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = absol(z[0]);
		z[0] = tmp * tmp - absol(z[1]) * absol(z[1]) + env->pt[0];
		z[1] = 2 * tmp * absol(z[1]) + env->pt[1];
		col -= env->colmod;
		if (col < 0)
			col = 0x00FFFFFF;
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : col), env);
}

void	julia(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];
	int		col;

	z[0] = (x - env->sx / 2) / env->zoom + env->move[0];
	z[1] = (y - env->sy / 2) / env->zoom + env->move[1];
	i = 0;
	col = 0x00FFFFFF;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = z[0];
		z[0] = tmp * tmp - z[1] * z[1] + env->pt[0];
		z[1] = 2 * tmp * z[1] + env->pt[1];
		col -= env->colmod;
		if (col < 0)
			col = 0x00FFFFFF;
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : col), env);
}

void	fractal(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];
	int		col;

	z[0] = (x - env->sx / 2) / env->zoom + env->move[0] / env->zoom;
	z[1] = (y - env->sy / 2) / env->zoom + env->move[1] / env->zoom;
	i = 0;
	col = 0x00FFFFFF;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = absol(z[0]);
		z[0] = tmp * tmp - absol(z[1]) * absol(z[1]) + env->pt[0];
		z[1] = 2 * tmp * absol(z[1]) + env->pt[1];
		col -= env->colmod;
		if (col < 0)
			col = 0x00FFFFFF;
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : col), env);
}
