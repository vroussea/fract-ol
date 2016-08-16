/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 18:40:34 by vroussea          #+#    #+#             */
/*   Updated: 2016/08/16 19:42:30 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_env *env)
{
	env->move[0] += (env->sx); //- new_size[0]) * env->rat_x;
	env->move[1] += (env->sy);// - new_size[1]) * env->rat_y;
}

double	absol(double val)
{
	return ((val < 0 ? val * (-1) : val));
}
