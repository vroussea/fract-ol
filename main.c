/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:40:59 by vroussea          #+#    #+#             */
/*   Updated: 2016/08/16 18:43:16 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

static void	caller(t_env *env, char *arg)
{
	if (ft_strcmp(arg, "Mandelbrot") == 0 || ft_strcmp(arg, "Burningship") == 0)
	{
		env->x1 = -2.1;
		env->y1 = -1.2;
		if (ft_strcmp(arg, "Mandelbrot") == 0)
			env->fract = 0;
		if (ft_strcmp(arg, "Burningship") == 0)
			env->fract = 2;
	}
	if (ft_strcmp(arg, "Julia") == 0 || ft_strcmp(arg, "Fractal") == 0)
	{
		env->x1 = -1.5;
		env->y1 = -1.5;
		if (ft_strcmp(arg, "Julia") == 0)
			env->fract = 1;
		if (ft_strcmp(arg, "Fractal") == 0)
			env->fract = 3;
	}
	mlx_hook(env->win, 6, 0, motion_funct, env);
	mlx_hook(env->win, 4, 0, zoom_funct, env);
	mlx_hook(env->win, 2, 0, key_funct, env);
	mlx_hook(env->win, 17, 0, quit_funct, env);
	fractals(env);
	mlx_loop(env->mlx);
}

static void	init_val(t_env *env, char *arg)
{
	int		bpp;
	int		edan;

	env->colmod = 135000;
	env->rat_x = 1;
	env->rat_y = 1;
	env->zoom = 250;
	env->pt[0] = 0.285;
	env->pt[1] = 0.01;
	env->i_max = 50;
	env->x_arc[0] = 0;
	env->x_arc[1] = env->sx;
	env->y_arc[0] = 0;
	env->y_arc[1] = env->sy;
	env->rat_x = 0;
	env->rat_y = 0;
	env->pos_x = 0;
	env->pos_y = 0;
	env->move[0] = env->x1;
	env->move[1] = env->y1;
	env->meml = mlx_get_data_addr(env->img, &bpp, &(env->sizel), &edan);
	caller(env, arg);
}

int			main(int argc, char **argv)
{
	t_env	*env;

	env = (t_env *)ft_memalloc(sizeof(t_env));
	env->sx = 750;
	env->sy = 600;
	if (argc < 2 || (ft_strcmp(argv[1], "Mandelbrot") != 0 &&
		ft_strcmp(argv[1], "Julia") != 0 &&
		ft_strcmp(argv[1], "Fractal") != 0 &&
		ft_strcmp(argv[1], "Burningship") != 0) ||
		!(env->mlx = mlx_init()) ||
		!(env->win = mlx_new_window(env->mlx, env->sx, env->sy, "Fract'ol")) ||
		!(env->img = mlx_new_image(env->mlx, env->sx, env->sy)))
	{
		ft_putendl("Accepted Parameters :");
		ft_putendl(" - Mandelbrot\n - Julia\n - Burningship\n - Fractal");
	}
	else
		init_val(env, argv[1]);
	return (0);
}
