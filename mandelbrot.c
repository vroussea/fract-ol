/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 19:50:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/06/16 21:19:05 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	mouse_mandel(int mouseclick, int x, int y, t_env *env)
{
	int	i;
	int	j;

	i = x;
	j = y;
	if (x > 0 && x < env->sx)
		env->dx += (x - env->sx / 2) / 2;
	if (y > 0 && y < env->sy)
		env->dy += (y - env->sy / 2) / 2;
	if (mouseclick == 1 || mouseclick == 4)
		env->zoom += 100 + (env->zoom / 100);
	if (mouseclick == 2 || mouseclick == 5)
		env->zoom -= 100;
	mandelbrot(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
	return (1);
}

static void	iterate(double x, double y, t_env env)
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
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + env.c_r;
		z_i = 2 * tmp * z_i + env.c_i;
		i++;
	}
	pixel(x - env.dx, y - env.dy, (i == env.i_max ? 0 : color(i, env.i_max)), env);
}

void		mandelbrot(t_env env)
{
	double		x;
	double		y;

	x = env.dx;
	while (x < env.sx + env.dx)
	{
		y = env.dy;
		while (y < env.sy + env.dy)
		{
			iterate(x, y, env);
			y++;
		}
		x++;
	}
}

void	mandeloop(t_env env)
{
	env.i_max = 50;
	env.x1 = -2.1;
	env.y1 = -1.2;
	mandelbrot(env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 1, 1);
	mlx_hook(env.win, 2, 0, key_funct, &env);
	mlx_hook(env.win, 17, 0, quit_funct, &env);
	mlx_hook(env.win, 4, 0, mouse_mandel, &env);
	mlx_loop(env.mlx);
}
