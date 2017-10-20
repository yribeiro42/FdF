/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:37:10 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/18 18:58:12 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *env)
{
	draw_map(env);
	return (0);
}

int		key_hook(int key, t_env *env)
{
	if (key == ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		free(env);
		exit(0);
	}
	if (key == PAGE_UP)
		zoom_in(env);
	if (key == PAGE_DOWN)
		zoom_out(env);
	if (key == PLUS)
		z_increase(env);
	if (key == MINUS)
		z_decrease(env);
	return (0);
}

int		clear_window(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	return (0);
}
