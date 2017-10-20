/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:21:56 by anonymous         #+#    #+#             */
/*   Updated: 2017/10/19 16:01:18 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env	*env;
	int		fd;

	if (argc == 2)
	{
		fd = 0;
		if (!(env = malloc(sizeof(t_env))))
			fdf_error3();
		count_lines(argv[1], env);
		parse(argv[1], env, fd);
		init_env(env);
		draw_map(env);
		mlx_key_hook(env->win, key_hook, env);
		mlx_expose_hook(env->win, expose_hook, env);
		mlx_loop(env->mlx);
	}
	else
		ft_putendl_fd("USAGE : ./fdf [INPUT FILE NAME]", 2);
	return (0);
}
