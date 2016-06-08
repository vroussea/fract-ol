/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:40:59 by vroussea          #+#    #+#             */
/*   Updated: 2016/06/08 22:07:02 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

void		pixel(int x, int y, int col, t_env env)
{
	if (x > 0 && x < env.sx && y > 0 && y < env.sy)
		ft_memcpy(&env.meml[(x - 1) * 4 + (y - 1) * env.sizel], &col, 4);
}

static void	fractals(t_env env, char *fract)
{
	if (ft_strcmp(fract, "Mandelbrot") == 0)
		mandelbrot(env);
//	if (ft_strcmp(fract, "Julia" == 0))
//		Julia(env);
//	if (ft_strcmp(fract, "" == 0))
//		mandelbrot(env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 1, 1);
}

int			main(int argc, char **argv)
{
	t_env	env;
	int		bpp;
	int		edan;

	env.sx = 2560;
	env.sy = 1315;
	if (argc < 2 || (ft_strcmp(argv[1], "Mandelbrot") != 0 &&
		ft_strcmp(argv[1], "Julia") != 0 && ft_strcmp(argv[1], "Autre") != 0) ||
		!(env.mlx = mlx_init()) ||
		!(env.win = mlx_new_window(env.mlx, env.sx, env.sy, "Fract'ol")) ||
		!(env.img = mlx_new_image(env.mlx, env.sx, env.sy)))
		ft_putendl("Accepted Parameters :\n - Mandelbrot\n - Julia\n - Autre");
	else
	{
		env.meml = mlx_get_data_addr(env.img, &bpp, &(env.sizel), &edan);
		mlx_hook(env.win, 2, 0, key_funct, &env);
		mlx_hook(env.win, 17, 0, quit_funct, &env);
		mlx_hook(env.win, 4, 0, mouse_funct, &env);
		fractals(env, argv[1]);
		mlx_loop(env.mlx);
	}
	return (0);
}
