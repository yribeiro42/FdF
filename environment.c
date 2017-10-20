/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:37:10 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/18 18:28:04 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FdF");
	env->zoom = 30;
	env->z_modifier = 2;
}

void	create_env(t_env *env)
{
	int bpp;
	int size_line;
	int endian;

	env->img_ptr = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_str = mlx_get_data_addr(env->img_ptr, &bpp, &size_line, &endian);
}

void	destroy_env(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img_ptr, 0, 0);
	mlx_destroy_image(env->mlx, env->img_ptr);
}

void	norm_x(t_env *env, int x, int y)
{
	projection_x(env, x, y);
	draw_line(env, x, y);
}

void	norm_y(t_env *env, int x, int y)
{
	projection_y(env, x, y);
	draw_line(env, x, y);
}
