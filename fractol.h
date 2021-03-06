/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:44:51 by vroussea          #+#    #+#             */
/*   Updated: 2016/09/06 19:30:55 by vroussea         ###   ########.fr       */
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
	int		fract;
	int		sizel;
	double	zoom;
	double	x1;
	double	y1;
	double	move[2];
	double	pt[2];
	int		i_max;
	int		pos_x;
	int		pos_y;
	int		colmod;
	int		is_move;
	int		is_indent;
	int		is_text;
}				t_env;

int				quit_funct(t_env *env);
int				key_funct(int keycode, t_env *env);
int				motion_funct(int x, int y, t_env *env);
int				zoom_funct(int mouseclick, int x, int y, t_env *env);
void			text(t_env *env);
void			special_text(t_env *env);
void			hud_text(t_env *env);
void			julia(int x, int y, t_env *env);
void			mandelbrot(int x, int y, t_env *env);
void			burning(int x, int y, t_env *env);
void			julol(int x, int y, t_env *env);
void			mandeldeux(int x, int y, t_env *env);
void			pixel(int x, int y, int col, t_env *env);
int				color(int i, int i_max);
void			fractals(t_env *env);
double			absol(double val);

#endif
