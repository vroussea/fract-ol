/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 18:40:34 by vroussea          #+#    #+#             */
/*   Updated: 2016/08/16 22:38:41 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

void	text(t_env *env)
{
	mlx_string_put(env->mlx, env->win, env->sx / 2, env->sy / 2, 0xFFFFFF, "mdr");
	mlx_string_put(env->mlx, env->win, env->sx / 2, env->sy / 2, 0xFFFFFF, "lol");
}

double	absol(double val)
{
	return ((val < 0 ? val * (-1) : val));
}
