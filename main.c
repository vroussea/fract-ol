/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:40:59 by vroussea          #+#    #+#             */
/*   Updated: 2016/06/22 23:46:53 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

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

double	absol(double val)
{
	if (val < 0)
		val = val * (-1);
	return (val);
}

static void	caller(t_env env, char *arg)
{
	int		bpp;
	int		edan;

	env.zoom = 1;
	env.meml = mlx_get_data_addr(env.img, &bpp, &(env.sizel), &edan);
	if (ft_strcmp(arg, "Mandelbrot") == 0)
		mandeloop(env);
	if (ft_strcmp(arg, "Julia") == 0)
		juloop(env);
	if (ft_strcmp(arg, "Burningship") == 0)
		burningloop(env);
	if (ft_strcmp(arg, "Fractal") == 0)
		fractloop(env);
}

int			main(int argc, char **argv)
{
	t_env	env;

	env.sx = 750;
	env.sy = 650;
	env.rat_x = 1;
	env.rat_y = 1;
	if (argc < 2 || (ft_strcmp(argv[1], "Mandelbrot") != 0 &&
		ft_strcmp(argv[1], "Julia") != 0 &&
		ft_strcmp(argv[1], "Fractal") != 0 &&
		ft_strcmp(argv[1], "Burningship") != 0) ||
		!(env.mlx = mlx_init()) ||
		!(env.win = mlx_new_window(env.mlx, env.sx, env.sy, "Fract'ol")) ||
		!(env.img = mlx_new_image(env.mlx, env.sx, env.sy)))
	{
		ft_putendl("Accepted Parameters :");
		ft_putendl(" - Mandelbrot\n - Julia\n - Burningship\n - Fractal");
	}
	else
		caller(env, argv[1]);
	return (0);
}
