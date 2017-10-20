/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:33:50 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/19 16:00:36 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error1(void)
{
	ft_putendl("File error");
	exit(1);
}

void	fdf_error2(void)
{
	ft_putendl("File format error");
	exit(1);
}

void	fdf_error3(void)
{
	ft_putendl("Malloc error");
	exit(1);
}
