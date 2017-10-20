/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:41:41 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/19 15:30:56 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	norm_draw(t_env *env)
{
	env->x_line = env->x1;
	env->y_line = env->y1;
}

int		set_color(t_env *env, int x, int y)
{
	int	average;

	average = 0;
	if (((env->rangemax - env->rangemin) / 2) != 0)
		average = ABS((env->rangemax - env->rangemin) / 2);
	if (env->map[y][x] > average)
		return (0xd7e149);
	if (env->map[y][x] == average)
		return (0xe15349);
	if (env->map[y][x] < average)
		return (0x498be1);
	else
		return (0x000000);
}

void	fill_pixel(t_env *env, int x, int y, int hexcolor)
{
	int pos;

	if (x < 0 || y < 0 || x >= WIDTH || y >= WIDTH)
		return ;
	pos = (4 * x) + (4 * y * WIDTH);
	env->img_str[pos] = hexcolor;
	env->img_str[pos + 1] = hexcolor >> 8;
	env->img_str[pos + 2] = hexcolor >> 16;
}

void	draw_line(t_env *env, int i, int j)
{
	double	dx;
	double	dy;
	double	slope;
	double	xi;
	double	yi;

	norm_draw(env);
	dx = (env->x2 + 1) - env->x1;
	dy = (env->y2 + 1) - env->y1;
	slope = (dx > dy) ? dx : dy;
	xi = dx / slope;
	yi = dy / slope;
	while (slope > 0)
	{
		env->x_line += xi;
		env->y_line += yi;
		if (env->x_line < WIDTH && env->y_line < HEIGHT)
			fill_pixel(env, env->x_line, env->y_line, set_color(env, i, j));
		slope--;
	}
}

void	draw_map(t_env *env)
{
	int x;
	int y;

	x = 0;
	y = 0;
	create_env(env);
	while (y != env->max_y)
	{
		x = 0;
		while (x != env->max_x)
		{
			env->x1 = x;
			env->y1 = y;
			if (x + 1 < env->max_x)
				norm_x(env, x, y);
			if (y + 1 < env->max_y)
				norm_y(env, x, y);
			x++;
		}
		y++;
	}
	destroy_env(env);
}
