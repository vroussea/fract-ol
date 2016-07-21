/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:48:41 by vroussea          #+#    #+#             */
/*   Updated: 2016/07/21 18:45:10 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

/*int	move_fract(int x, int y, t_env *env)
{
	env->c_r = (double)x / 1000;
	env->c_i = (double)y / 1000;
	fract(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
	return (1);
}*/

/*int	mouse_burning(int mouseclick, int x, int y, t_env *env)
{
	int	i;
	int	j;

	i = x;
	j = y;
	if (mouseclick == 1 || mouseclick == 4)
		env->zoom += 5;
	if (mouseclick == 2 || mouseclick == 5)
		env->zoom -= 5;
	burningship(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
	return (1);
}*/

int	zoom_funct(int mouseclick, int x, int y, t_env *env)
{
	if (x > 0 && y > 0 && x < env->sx && y < env->sy && mouseclick != 3)
	{
		env->rat_x = (double)x / (double)env->sx;
		env->rat_y = (double)y / (double)env->sy;
		if (mouselick == 1 || mouseclick == 4)
			env->zoom += 0.01;
		else if ((mouseclick == 2 || mouseclick == 5) && env->zoom > 0.010)
			env->zoom -= 0.01;
		else return (0);
		zoom(env);
		iterate(*env);
	}
	return (1);
}

int	key_funct(int keycode, t_env *env)
{
	if (keycode == 53)
		quit_funct(env);
	iterate(*env);
	return (1);
}

int	motion_funct(int x, int y, t_env *env)
{
	env->pt[0] = (double)x / 1000;
	env->pt[1] = (double)y / 1000;
	iterate(*env);
	return (1);
}

int	quit_funct(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	ft_putendl("Program Closed");
	exit(0);
	return (1);
}
