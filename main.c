/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:40:59 by vroussea          #+#    #+#             */
/*   Updated: 2016/06/11 18:37:12 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static void	juloop(t_env env)
{
	env.i_max = 150;
	env.x1 = -1.5;
	env.y1 = -1.5;
	env.c_r = 0.285;
	env.c_i = 0.01;
	julia(env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 1, 1);
	mlx_hook(env.win, 2, 0, key_funct, &env);
	mlx_hook(env.win, 17, 0, quit_funct, &env);
	mlx_hook(env.win, 6, 0, move_julia, &env);
	mlx_loop(env.mlx);
}

static void	mandeloop(t_env env)
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

int			main(int argc, char **argv)
{
	t_env	env;
	int		bpp;
	int		edan;

	env.sx = 750;
	env.sy = 650;
	if (argc < 2 || (ft_strcmp(argv[1], "Mandelbrot") != 0 &&
		ft_strcmp(argv[1], "Julia") != 0 && ft_strcmp(argv[1], "Autre") != 0) ||
		!(env.mlx = mlx_init()) ||
		!(env.win = mlx_new_window(env.mlx, env.sx, env.sy, "Fract'ol")) ||
		!(env.img = mlx_new_image(env.mlx, env.sx, env.sy)))
		ft_putendl("Accepted Parameters :\n - Mandelbrot\n - Julia\n - Autre");
	else
	{
		env.col = 0x000000;
		env.zoom = 250;
		env.meml = mlx_get_data_addr(env.img, &bpp, &(env.sizel), &edan);
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
			mandeloop(env);
		if (ft_strcmp(argv[1], "Julia") == 0)
			juloop(env);
//		if (ft_strcmp(argv[1], "Autre") == 0)
//			loop(env, argv[1]);
	}
	return (0);
}
