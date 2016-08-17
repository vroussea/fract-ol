/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:09:06 by vroussea          #+#    #+#             */
/*   Updated: 2016/08/17 20:37:08 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static void	iterate(void (*funct)(int, int, t_env *), t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < env->sx)
	{
		y = 0;
		while (y < env->sy)
		{
			funct(x, y, env);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
	text(env);
}

void		fractals(t_env *env)
{
	void	(*funct)(int, int, t_env *);

	if (env->fract == 0)
		funct = &mandelbrot;
	if (env->fract == 1)
		funct = &julia;
	if (env->fract == 2)
		funct = &burning;
	if (env->fract == 3)
		funct = &fractal;
	if (env->fract == 4)
		funct = &autre;
	iterate(funct, env);
}
