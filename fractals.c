/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:09:06 by vroussea          #+#    #+#             */
/*   Updated: 2016/09/06 19:30:45 by vroussea         ###   ########.fr       */
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
	if (env->is_text == 1)
	{
		if (env->fract == 1 || env->fract == 3)
			special_text(env);
		text(env);
	}
	hud_text(env);
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
		funct = &julol;
	if (env->fract == 4)
		funct = &mandeldeux;
	iterate(funct, env);
}
