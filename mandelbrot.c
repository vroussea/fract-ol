/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 19:50:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/06/22 23:45:34 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdio.h>

/*int			mouse_mandel(int mouseclick, int x, int y, t_env *env)
{
	if (x > 0 && x < env->sx)
		env->dx += (x - env->sx / 2) / 2;
	if (y > 0 && y < env->sy)
		env->dy += (y - env->sy / 2) / 2;
	if (mouseclick == 1 || mouseclick == 4)
	{
		env->zoom += 100;
		env->x1 += (100 / env->zoom);
		env->y1 += (100 / env->zoom);
	}
	if (mouseclick == 2 || mouseclick == 5)
	{
		env->zoom -= 100;
		env->x1 -= (100 / env->zoom);
		env->y1 += (100 / env->zoom);
	}
	mandelbrot(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
	return (1);
}*/

int			mouse_mandel(int mouseclick, int x, int y, t_env *env)
{
	if (x > 0 && x < env->sx && mouseclick != 3)
		env->rat_x = (double)x / env->sx;
	if (y > 0 && y < env->sy && mouseclick != 3)
		env->rat_y = (double)y / env->sy;
	if (mouseclick == 1 || mouseclick == 4)
		env->zoom += 0.01;
	if ((mouseclick == 2 || mouseclick == 5) && env->zoom > 0.01000)
		env->zoom -= 0.01;
	mandelbrot(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
	return (1);
}

static void	iterate(int x, int y, t_env env)
{
	int	i;
	double	tmp;
	double	z_r;
	double	z_i;

	z_r = 0;
	z_i = 0;
	env.c_r = env.rat_x / (env.zoom * 250) + env.x1;
	env.c_i = env.rat_y / (env.zoom * 250) + env.y1;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < env.i_max) 
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + env.c_r;
		z_i = 2 * tmp * z_i + env.c_i;
		i++;
	}
	pixel(x, y, (i == env.i_max ? 0 : color(i, env.i_max)), env);
}

void		mandelbrot(t_env env)
{
	int		x;
	int		y;
	double	x_max;
	double	y_max;

	x = 0;

	env.x_min = (env.sx - (env.sx / env.zoom)) * env.rat_x;
	env.y_min = (env.sy - (env.sy / env.zoom)) * env.rat_y;
	x_max = env.sx - ((env.sx - (env.sx * env.rat_x)) / env.zoom);//env.rat_x + (env.sx / env.zoom);
	y_max = env.sy - ((env.sy - (env.sy * env.rat_y)) / env.zoom);//env.rat_y + (env.sy / env.zoom);
	printf("x max : %f x min : %f rat x : %f zm : %f sx : %d\n", x_max, env.x_min, env.rat_x, env.zoom, env.sx);
	printf("y max : %f y min : %f rat y : %f zm : %f sy : %d\n", y_max, env.y_min, env.rat_y, env.zoom, env.sy);
	env.rat_x = env.x_min;
	while (x < env.sx)
	{
		y = 0;
		env.rat_y = env.y_min;
		while (y < env.sy)
		{
			iterate(x, y, env);
			env.rat_y += (y_max - env.y_min) / env.sy;
			y++;
		}
		if (x == 0)
			printf("nb iteration en y : %d\n", y);
		env.rat_x += (x_max - env.x_min) / env.sx;
		x++;
	}
	printf("nb iteration en x : %d\n", x);
}

void		mandeloop(t_env env)
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
