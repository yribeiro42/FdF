/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:37:10 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/19 15:15:37 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_x(t_env *env, int x, int y)
{
	int x_tile;
	int y_tile;

	x_tile = x - env->max_x / 2;
	y_tile = y - env->max_y / 2;
	env->x1 = (x_tile - y_tile) * 0.5 * env->zoom;
	env->y1 = (x_tile + y_tile) * 0.3 * env->zoom;
	env->y1 -= env->map[y][x] * env->z_modifier;
	env->x2 = ((x_tile + 1) - y_tile) * 0.5 * env->zoom;
	env->y2 = ((x_tile + 1) + y_tile) * 0.3 * env->zoom;
	env->y2 -= env->map[y][x + 1] * env->z_modifier;
	env->x1 += WIDTH * 0.5;
	env->x2 += WIDTH * 0.5;
	env->y1 += HEIGHT * 0.5;
	env->y2 += HEIGHT * 0.5;
}

void	projection_y(t_env *env, int x, int y)
{
	int x_tile;
	int y_tile;

	x_tile = x - env->max_x / 2;
	y_tile = y - env->max_y / 2;
	env->x1 = (x_tile - y_tile) * 0.5 * env->zoom;
	env->y1 = (x_tile + y_tile) * 0.3 * env->zoom;
	env->y1 -= env->map[y][x] * env->z_modifier;
	env->x2 = (x_tile - (y_tile + 1)) * 0.5 * env->zoom;
	env->y2 = (x_tile + (y_tile + 1)) * 0.3 * env->zoom;
	env->y2 -= env->map[y + 1][x] * env->z_modifier;
	env->x1 += WIDTH * 0.5;
	env->x2 += WIDTH * 0.5;
	env->y1 += HEIGHT * 0.5;
	env->y2 += HEIGHT * 0.5;
}
