/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 19:50:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/06/07 21:52:25 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	is_colored(int x, int y, t_env env, int i_max)
{
	int	i;
	int	tmp;
	int	z_r;
	int	z_i;

	i = 0;
	z_r = 0;
	z_i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < i_max) 
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + x;
		z_i = 2 * tmp * z_i + y;
		i++;
	}
	if (i == i_max)
		pixel(x, y, 0x000000, env);
	else
		pixel(x, y, 0x0000FF * i / i_max, env);
}

void		mandelbrot(t_env env)
{
	int		x;
	int		y;

	x = 0;
	while (x < env.sx)
	{
		y = 0;
		while (y < env.sy)
		{
			is_colored(x, y, env, 50);
			y++;
		}
		x++;
	}
}
