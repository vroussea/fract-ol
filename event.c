/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:48:41 by vroussea          #+#    #+#             */
/*   Updated: 2016/07/25 19:51:22 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <stdlib.h>

int	zoom_funct(int mouseclick, int x, int y, t_env *env)
{
	ft_putendl("test souris 1");
	if (x > 0 && y > 0 && x < env->sx && y < env->sy && mouseclick != 3)
	{
		env->rat_x = (double)x / (double)env->sx;
		env->rat_y = (double)y / (double)env->sy;
		if (mouseclick == 1 || mouseclick == 4)
			env->zoom += 0.01;
		else if ((mouseclick == 2 || mouseclick == 5) && env->zoom > 0.010)
			env->zoom -= 0.01;
		else return (0);
		zoom(env);
		iterate(env);
	}
	ft_putendl("test souris 2");
	return (1);
}

int	key_funct(int keycode, t_env *env)
{
	ft_putendl("test touche 1");
	if (keycode == 53)
		quit_funct(env);
	iterate(env);
	ft_putendl("test touche 2");
	return (1);
}

int	motion_funct(int x, int y, t_env *env)
{
	ft_putendl("test mouvement 1");
	env->pt[0] = (double)x / 1000;
	env->pt[1] = (double)y / 1000;
	iterate(env);
	ft_putendl("test mouvement 2");
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
