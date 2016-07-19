/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:44:51 by vroussea          #+#    #+#             */
/*   Updated: 2016/07/18 17:55:32 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	int		sx;
	int		sy;
	void	*img;
	char	*meml;
	int		sizel;
	double	zoom;
	double	rat_x;
	double	rat_y;
	double	x1;
	double	y1;
	double	x_arc[2];
	double	y_arc[2];
	double	pt[2];
	int		i_max;
}				t_env;

int				quit_funct(t_env *env);
int				key_funct(int keycode, t_env *env);
int				mouse_mandel(int mouseclick, int x, int y, t_env *env);
int				mouse_burning(int mouseclick, int x, int y, t_env *env);
int				move_julia(int x, int y, t_env *env);
int				move_fract(int x, int y, t_env *env);
void			julia(t_env env);
void			mandelbrot(t_env env);
void			burningship(t_env env);
void			fract(t_env env);
void			pixel(int x, int y, int col, t_env env);
int				color(int i, int i_max);
void			juloop(t_env env);
void			mandeloop(t_env env);
void			burningloop(t_env env);
void			fractloop(t_env env);
double			absol(double val);

#endif
