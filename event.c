/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:48:41 by vroussea          #+#    #+#             */
/*   Updated: 2016/09/06 19:22:45 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>

int	zoom_funct(int mouseclick, int x, int y, t_env *env)
{
	env->pos_x = (double)x;
	env->pos_y = (double)y;
	if (mouseclick == 1 || mouseclick == 4)
	{
		env->move[0] += (x - env->sx / 2) / env->zoom;
		env->move[1] += (y - env->sy / 2) / env->zoom;
		env->zoom *= 1.5;
		env->move[0] -= (x - (env->sx / 2)) / env->zoom;
		env->move[1] -= (y - (env->sy / 2)) / env->zoom;
		env->i_max = (env->is_indent == 0 ? env->i_max + 10 : env->i_max);
	}
	if ((mouseclick == 2 || mouseclick == 5))
	{
		env->move[0] += (x - env->sx / 2) / env->zoom;
		env->move[1] += (y - env->sy / 2) / env->zoom;
		env->zoom /= 1.5;
		env->move[0] -= (x - (env->sx / 2)) / env->zoom;
		env->move[1] -= (y - (env->sy / 2)) / env->zoom;
		env->i_max = (env->is_indent == 0 && env->i_max > 30 ?
				env->i_max - 10 : env->i_max);
	}
	fractals(env);
	return (1);
}

int	key_funct(int keycode, t_env *env)
{
	if (keycode == 53)
		quit_funct(env);
	if (keycode == 69 || keycode == 78)
		env->colmod += (keycode == 69 ? 5000 : -5000);
	if (keycode == 75 || keycode == 67)
		env->zoom = (keycode == 75 ? env->zoom * 1.3 : env->zoom / 1.3);
	if (keycode == 116)
		env->i_max += 10;
	if (keycode == 121)
		(env->i_max > 0 ? env->i_max -= 10 : 0);
	if (keycode == 123 || keycode == 124)
		env->move[0] += (keycode == 123 ? 10 / env->zoom : -(10 / env->zoom));
	if (keycode == 126 || keycode == 125)
		env->move[1] += (keycode == 126 ? 10 / env->zoom : -(10 / env->zoom));
	if (keycode == 119)
		env->is_move = (env->is_move == 1 ? 0 : 1);
	if (keycode == 115)
		env->is_indent = (env->is_indent == 1 ? 0 : 1);
	if (keycode == 117)
		env->is_text = (env->is_text == 1 ? 0 : 1);
	fractals(env);
	return (1);
}

int	motion_funct(int x, int y, t_env *env)
{
	if (env->is_move == 1)
	{
		env->pt[0] = (double)x / 1000;
		env->pt[1] = (double)y / 1000;
	}
	fractals(env);
	return (1);
}

int	quit_funct(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	ft_memdel((void **)&env);
	ft_putendl("Program Closed");
	exit(0);
	return (1);
}
