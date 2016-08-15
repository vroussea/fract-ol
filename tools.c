/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 18:40:34 by vroussea          #+#    #+#             */
/*   Updated: 2016/08/14 15:17:29 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_env *env)
{
	double	new_size[2];
	double	prev_x[2];
	double	prev_y[2];

	new_size[0] = env->sx / env->zoom;
	new_size[1] = env->sy / env->zoom;
	prev_x[0] = env->x_arc[0];
	prev_x[1] = env->x_arc[1];
	prev_y[0] = env->y_arc[0];
	prev_y[1] = env->y_arc[1];
	env->x_arc[0] = prev_x[0] + new_size[0] * env->rat_x;
	env->y_arc[0] = prev_y[0] + new_size[1] * env->rat_y;
	env->x_arc[1] = env->x_arc[0] + new_size[0];
	env->y_arc[1] = env->y_arc[0] + new_size[1];
}

double	absol(double val)
{
	return ((val < 0 ? val * (-1) : val));
}
