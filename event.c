/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:48:41 by vroussea          #+#    #+#             */
/*   Updated: 2016/07/17 16:27:21 by vroussea         ###   ########.fr       */
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
