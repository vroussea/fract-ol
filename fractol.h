/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:44:51 by vroussea          #+#    #+#             */
/*   Updated: 2016/06/09 16:33:48 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"

#define X1 -2.1
#define X2 0.6
#define Y1 -1.2
#define Y2 1.2

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	int		sx;
	int		sy;
	void	*img;
	char	*meml;
	int		sizel;
	int		zoom;
	double	c_r;
	double	c_i;
	double	x1;
	double	y1;
	int		col;
	int		i_max;
}				t_env;

int				quit_funct(t_env *env);
int				key_funct(int keycode, t_env *env);
int				mouse_mandel(int mouseclick, int x, int y, t_env *env);
int				move_julia(int x, int y, t_env *env);
void			julia(t_env env);
void			mandelbrot(t_env env);
void			pixel(int x, int y, int col, t_env env);

#endif
