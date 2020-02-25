/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <ramoukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:45:01 by ramoukha          #+#    #+#             */
/*   Updated: 2020/02/25 15:25:47 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	manage_values(t_point *start, t_env *env, int x, int y)
{
	*start = (t_point){25 * x, 25 * y, env->store.tab[y][x]};
	if (env->store.tab[y][x] != 0)
		(*start).z *= env->up;
	env->iso ? iso(&(*start).x, &(*start).y, (*start).z) : 0;
}

void	manage_values2(t_env *env, t_point *start, t_point *end)
{
	if (env->store.tab[env->y][env->x + 1])
		end->z *= env->up;
	env->iso ? iso(&end->x, &end->y, end->z) : 0;
	start->x += env->h;
	end->x += env->h;
	start->y += env->v;
	end->y += env->v;
	line(*start, *end, env);
}

void	manage_values3(int x, t_env *env, t_point *start, t_point *end)
{
	if (env->store.tab[env->y + 1][env->x])
		end->z *= env->up;
	env->iso ? iso(&end->x, &end->y, end->z) : 0;
	if (x == env->store.w - 1)
	{
		start->y += env->v;
		start->x += env->h;
	}
	end->x += env->h;
	end->y += env->v;
	line(*start, *end, env);
}

void	ft_map_debug(t_env *env)
{
	t_point	start;
	t_point	end;

	env->y = -1;
	while (++env->y < env->store.h)
	{
		env->x = -1;
		while (++env->x < env->store.w)
		{
			manage_values(&start, env, env->x, env->y);
			if (env->x < env->store.w - 1)
			{
				end = (t_point){ 25 * (env->x + 1), 25 *
					(env->y), env->store.tab[env->y][env->x + 1]};
				manage_values2(env, &start, &end);
			}
			if (env->y < env->store.h - 1)
			{
				end = (t_point){25 * env->x, 25 *
					(env->y + 1), env->store.tab[env->y + 1][env->x]};
				manage_values3(env->x, env, &start, &end);
			}
		}
	}
}

int		main(int argc, char **argv)
{
	t_env	env;

	ft_bzero(&env.store, sizeof(t_store));
	if (argc != 2)
		ft_usage();
	env.iso = 0;
	env.h = 0;
	env.up = 1;
	env_init(&env, argv[1]);
	ft_map_debug(&env);
	mlx_hook(env.mlx.mlx_win, 17, 0, ft_close, &env);
	mlx_hook(env.mlx.mlx_win, 2, 0, ft_key_pressed, &env);
	mlx_loop(env.mlx.mlx_ptr);
	return (0);
}
