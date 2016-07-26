/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:09:06 by vroussea          #+#    #+#             */
/*   Updated: 2016/07/26 19:19:25 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static void	iterate(void (*funct)(int, int, t_env *), t_env *env)
{
	int		x;
	int		y;
	
	env->rat_x = env->x_arc[0];
	x = 0;
	while (x < env->sx)
	{
		y = 0;
		env->rat_y = env->y_arc[0];
		while (y < env->sy)
		{	
			funct(x, y, env);
			env->rat_y += (env->y_arc[1] - env->y_arc[0]) / env->sy;
			y++;
		}
		env->rat_x += (env->x_arc[1] - env->x_arc[0]) / env->sx;
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
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
	iterate(funct, env);
}
