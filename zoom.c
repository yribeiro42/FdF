/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:37:10 by yribeiro          #+#    #+#             */
/*   Updated: 2017/05/09 16:01:43 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_env *env)
{
	env->zoom += 1;
	clear_window(env);
	expose_hook(env);
}

void	zoom_out(t_env *env)
{
	env->zoom -= 1;
	clear_window(env);
	expose_hook(env);
}

void	z_increase(t_env *env)
{
	env->z_modifier += 1;
	clear_window(env);
	expose_hook(env);
}

void	z_decrease(t_env *env)
{
	env->z_modifier -= 1;
	clear_window(env);
	expose_hook(env);
}
