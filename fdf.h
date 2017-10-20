/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:37:10 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/19 16:04:58 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "minilibxmacos/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define ABS(x) ((x) < 0 ? (-x) : (x))
# define WIDTH 1280
# define HEIGHT 720
# define LIMIT	9999
# define ESC 53
# define PAGE_UP 116
# define PAGE_DOWN 121
# define PLUS 24
# define MINUS 27

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			**map;
	int			max_x;
	int			max_y;
	char		*img_str;
	void		*img_ptr;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			zoom;
	int			z_modifier;
	double		x_line;
	double		y_line;
	int			rangemax;
	int			rangemin;
}				t_env;

int				count_points(char *str);
void			count_lines(char *argv, t_env *env);
void			parse(char *argv, t_env *env, int fd);
void			init_env(t_env *env);
void			create_env(t_env *env);
void			destroy_env(t_env *env);
int				set_color(t_env *env, int x, int y);
void			fill_pixel(t_env *env, int x, int y, int color);
void			draw_line(t_env *env, int i, int j);
void			draw_map(t_env *env);
void			init_projection(t_env *env, int x, int y);
void			projection_x(t_env *env, int x, int y);
void			projection_y(t_env *env, int x, int y);
int				key_hook(int key, t_env *env);
void			zoom_in(t_env *env);
void			zoom_out(t_env *env);
int				expose_hook(t_env *env);
int				clear_window(t_env *env);
void			z_increase(t_env *env);
void			z_decrease(t_env *env);
void			fdf_error1(void);
void			fdf_error2(void);
void			fdf_error3(void);
void			fdf_error4(void);
void			norm_x(t_env *env, int x, int y);
void			norm_y(t_env *env, int x, int y);
void			norm_draw(t_env *env);
void			max_range(t_env *env, int splitx);

#endif
