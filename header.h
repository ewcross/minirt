/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:31:30 by ecross            #+#    #+#             */
/*   Updated: 2020/02/12 19:32:26 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "structs.h"
# include "mlx.h"
# include "libft.h"
# include "libgnl.h"
# include "x11.h"

# define CHARSET "RAclspt"
# define R 0
# define G 1
# define B 2
# define X 0
# define Y 1
# define Z 2

void	sp_normal(double *surface_xyz, t_obj_struct *obj, double *norm);
void    p_normal(double *surface_xyz, t_obj_struct *obj, double *norm);
void	sq_normal(double *surface_xyz, t_obj_struct *obj, double *norm);
int		set_keys(int keycode, void *t_win_struct);
int		pos_in_set(char ch, char *set);
void	init_parse_func_arr(int (*func_arr[])(char *, t_scene_struct *));
int		parse_line(char *line, t_scene_struct *s);
int		len_str_arr(char **str_arr);
int		simple_atoi(char *str);
void	print_elem(t_obj_struct *elem);
void	init_win_struct(t_win_struct *ws);
int		parser(t_scene_struct *s, char *file);
int		r_func(char *line, t_scene_struct *s);
int		a_func(char *line, t_scene_struct *s);
int		c_func(char *line, t_scene_struct *s);
int		l_func(char *line, t_scene_struct *s);
int		s_func(char *line, t_scene_struct *s);
int		p_func(char *line, t_scene_struct *s);
int		t_func(char *line, t_scene_struct *s);
int		cam_func(char *line, t_scene_struct *s);
int		cy_func(char *line, t_scene_struct *s);
int		sp_func(char *line, t_scene_struct *s);
int		sq_func(char *line, t_scene_struct *s);

#endif
