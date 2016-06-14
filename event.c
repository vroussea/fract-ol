/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:48:41 by vroussea          #+#    #+#             */
/*   Updated: 2016/06/14 21:40:55 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <stdlib.h>

int	move_julia(int x, int y, t_env *env)
{
	env->c_r = (double)x / 1000;
	env->c_i = (double)y / 1000;
	julia(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
	return (1);
}

int	mouse_burning(int mouseclick, int x, int y, t_env *env)
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
}

int	mouse_mandel(int mouseclick, int x, int y, t_env *env)
{
	int	i;
	int	j;

	i = x;
	j = y;
	if (mouseclick == 1 || mouseclick == 4)
		env->zoom += 5;
	if (mouseclick == 2 || mouseclick == 5)
		env->zoom -= 5;
	mandelbrot(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
	return (1);
}

int	key_funct(int keycode, t_env *env)
{
	if (keycode == 53)
		quit_funct(env);
	return (0);
}

int	quit_funct(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	ft_putendl("Program Closed");
	exit(0);
	return (1);
}
