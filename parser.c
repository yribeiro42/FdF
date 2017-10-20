/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:37:10 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/19 16:01:30 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_points(char *str)
{
	int	k;
	int	flag;
	int nb;

	k = 0;
	flag = 1;
	nb = 0;
	while (str[k])
	{
		if (str[k] == ' ')
			flag = 1;
		if (flag == 1 && str[k] != ' ')
		{
			nb++;
			flag = 0;
		}
		k++;
	}
	return (nb);
}

void	max_range(t_env *env, int splitx)
{
	if (env->rangemax > splitx)
		env->rangemax = splitx;
	if (env->rangemin < splitx)
		env->rangemin = splitx;
}

void	count_lines(char *argv, t_env *env)
{
	int		fd;
	int		nb_line;
	int		max_len;
	char	*line;

	nb_line = 0;
	max_len = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		fdf_error1();
	while (get_next_line(fd, &line) == 1 && nb_line < LIMIT)
	{
		if (ft_strlen(line) == 0)
			fdf_error2();
		if (count_points(line) > max_len)
			max_len = count_points(line);
		env->max_x = count_points(line);
		if (env->max_x != max_len)
			fdf_error2();
		nb_line++;
	}
	if (nb_line == LIMIT || !nb_line)
		fdf_error2();
	close(fd);
	env->max_x = max_len;
	env->max_y = nb_line;
}

void	parse(char *argv, t_env *env, int fd)
{
	char	*line;
	char	**split;
	int		x;
	int		y;

	y = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		fdf_error1();
	if (!(env->map = malloc((env->max_y) * sizeof(int *))))
		fdf_error3();
	while (get_next_line(fd, &line) == 1 && y != env->max_y)
	{
		x = 0;
		if (!(env->map[y] = malloc((count_points(line)) * sizeof(int))))
			fdf_error3();
		split = ft_strsplit(line, ' ');
		while (split[x])
		{
			env->map[y][x] = ft_atoi(split[x]);
			max_range(env, ft_atoi(split[x]));
			x++;
		}
		y++;
	}
	close(fd);
}
