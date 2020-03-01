/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <ramoukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:20:13 by ramoukha          #+#    #+#             */
/*   Updated: 2020/01/08 14:38:41 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

void	line(t_point start, t_point end, t_env *env)
{
	t_utils	p;

	p = (t_utils){abs(end.x - start.x), -abs(end.y - start.y), 0, 0, 0, 0, 0};
	p.sx = start.x < end.x ? 1 : -1;
	p.sy = start.y < end.y ? 1 : -1;
	p.dp = p.dx + p.dy;
	p.c = start.z > end.z ? start.z : end.z;
	while (1)
	{
		p.e2 = 2 * p.dp;
		mlx_pixel_put(env->mlx.mlx_ptr, env->mlx.mlx_win,\
				start.x, start.y, 0xFFFFFF - ((p.c * 10000) % 0xFFFFFF));
		if (start.x == end.x && start.y == end.y)
			break ;
		if (p.e2 >= p.dy)
		{
			p.dp += p.dy;
			start.x += p.sx;
		}
		if (p.e2 <= p.dx)
		{
			p.dp += p.dx;
			start.y += p.sy;
		}
	}
}
