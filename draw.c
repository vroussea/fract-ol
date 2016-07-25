/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:12:09 by vroussea          #+#    #+#             */
/*   Updated: 2016/07/25 19:47:21 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	pixel(int x, int y, int col, t_env *env)
{
	if (x > 0 && x < env->sx && y > 0 && y < env->sy)
		ft_memcpy(&env->meml[(x - 1) * 4 + (y - 1) * env->sizel], &col, 4);
}

int		color(int i, int i_max)
{
	unsigned char	*pt;
	int				col;

	col = 0xFFFFFF * pow(i, 1.99) / i_max;
	pt = (unsigned char *)&col;
	pt[3] = 0x00;
	pt[2] = (pt[2] < 100 ? pt[2] + 70 : pt[2]);
	return (col);
}
