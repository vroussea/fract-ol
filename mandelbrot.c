/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 19:50:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/07/18 21:21:37 by vroussea         ###   ########.fr       */
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
	double	new_size[2];
	
	if (x > 0 && x < env->sx && mouseclick != 3)
		env->rat_x = (double)x / env->sx;
	if (y > 0 && y < env->sy && mouseclick != 3)
		env->rat_y = (double)y / env->sy;
	if (mouseclick == 1 || mouseclick == 4)
		env->zoom += 0.01;
	else if ((mouseclick == 2 || mouseclick == 5) && env->zoom > 0.01000)
		env->zoom -= 0.01;
	else
		return (1);
	new_size[0] = env->sx / env->zoom;
	new_size[1] = env->sy / env->zoom;
	printf("min x avant : %f | min y avant : %f\n", env->x_arc[0], env->y_arc[0]);
	env->x_arc[0] = (env->sx - new_size[0]) * env->rat_x;
	env->y_arc[0] = (env->sy - new_size[1]) * env->rat_y;
	printf("rat x : %f | rat y : %f\n", env->rat_x, env->rat_y);
	printf("size : %f | size : %f\n", new_size[0], new_size[1]);
	printf("size* rat x : %f | size* rat y : %f\n", (env->sx - new_size[0]) * env->rat_x, (env->sy - new_size[1]) * env->rat_y);
	printf("min x apres : %f | min y apres : %f\n", env->x_arc[0], env->y_arc[0]);
	env->x_arc[1] = env->x_arc[0] + new_size[0];
	env->y_arc[1] = env->y_arc[0] + new_size[1];
	printf("size : %f | size : %f\n\n", env->x_arc[0] + (env->sx - env->x_arc[1]) + new_size[0], env->y_arc[0] + (env->sy - env->y_arc[1]) + new_size[1]);
	mandelbrot(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
	return (1);
}

static void	iterate(int x, int y, t_env env)
{
	int	i;
	double	tmp;
	double	z[2];

	z[0] = 0;
	z[1] = 0;
	env.pt[0] = env.rat_x / (env.zoom * 250) + env.x1;
	env.pt[1] = env.rat_y / (env.zoom * 250) + env.y1;
	i = 0;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env.i_max) 
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + env.pt[0];
		z[1] = 2 * tmp * z[1] + env.pt[1];
		i++;
	}
	pixel(x, y, (i == env.i_max ? 0 : color(i, env.i_max)), env);
}

void		mandelbrot(t_env env)
{
	int		x;
	int		y;

	x = 0;
	env.rat_x = env.x_arc[0];
	while (x < env.sx)
	{
		y = 0;
		env.rat_y = env.y_arc[0];
		while (y < env.sy)
		{
			iterate(x, y, env);
			env.rat_y += (env.y_arc[1] - env.y_arc[0]) / env.sy;
			y++;
		}
		env.rat_x += (env.x_arc[1] - env.x_arc[0]) / env.sx;
		x++;
	}
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
