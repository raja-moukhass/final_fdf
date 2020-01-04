/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <ramoukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:45:01 by ramoukha          #+#    #+#             */
/*   Updated: 2020/01/04 15:21:26 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/fdf.h"
#include <stdio.h>
void	env_init(t_env *env, char *s)
{
	env->mlx.mlx_ptr = mlx_init();
	env->mlx.mlx_win = mlx_new_window(env->mlx.mlx_ptr, 6000, 3000, "FDF");
	ft_store_fdf(&env->store, s);
	env->u = (t_point){100, 200, 0};
}

int 	ft_close(void	*ptr)
{
	t_env	*env;
	
	env = (t_env*)ptr;
	mlx_clear_window(env->mlx.mlx_ptr, env->mlx.mlx_win);
	exit(EXIT_SUCCESS);
	return (1);
}

int 	ft_key_pressed(int keycode, void   *ptr)
{
	t_env 	*env;

	env = (t_env *)ptr;
	if (keycode == 53)
		ft_close(env);
	if	(keycode == 78)
		env->iso = env->iso == 0 ? 1 : 0;
	if (keycode ==  124)
		env->h += 10;
	if (keycode == 123)
	env->h -= 10;
	if (keycode == 125)
	env->v += 10;
	if (keycode == 126)
	env->v -= 10;
	if (keycode == 116)
	env-> up += 1;
	if (keycode == 121)
	env -> up -= 1;
	mlx_clear_window(env->mlx.mlx_ptr, env->mlx.mlx_win);
	ft_map_debug(env);
	return (1);
}

void    iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;
	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

void line(t_point start, t_point end, t_env *env) 
{
	t_utils	p;
	
	p = (t_utils){abs(end.x - start.x), -abs (end.y - start.y), 0, 0, 0, 0, 0};
	p.sx = start.x < end.x ? 1 : -1;
	p.sy = start.y < end.y ? 1 : -1;
	p.dp = p.dx + p.dy;
	p.c = start.z > end.z ? start.z : end.z;
	while (1)
	{
		p.e2 = 2 * p.dp;
		mlx_pixel_put(env->mlx.mlx_ptr, env->mlx.mlx_win,\
				start.x, start.y, 0xFFFFFF - ((p.c * 10000) % 0xFFFF00));
		if (start.x == end.x && start.y == end.y)
			break;
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

void	manage_values(t_point *start, t_env *env, int x, int y)
{
	*start = (t_point){  10* x, 10* y, env->store.tab[y][x]};
	if (env->store.tab[y][x] != 0)
		(*start).z *= env->up;
	env->iso ? iso(&(*start).x, &(*start).y , (*start).z) : 0;
}

void	manage_values2(t_env *env, t_point *start, t_point *end)
{
	if (env->store.tab[env->y][env->x+1])
		end->z *= env->up;
	env->iso ? iso(&end->x, &end->y , end->z) : 0;
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
	env->iso ? iso(&end->x, &end->y , end->z) : 0;
	if (x == env->store.w - 1)
	{
		start->y+= env->v;
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
				end = (t_point){ 10* (env->x + 1), 10*
					(env->y), env->store.tab[env->y][env->x + 1]};
				manage_values2(env, &start, &end);
			}
			if (env->y < env->store.h - 1)
			{
				end = (t_point){10* env->x, 10*
					(env->y + 1), env->store.tab[env->y + 1][env->x]};
				manage_values3(env->x, env, &start, &end);
			}
		}
	}
}

int		main(int argc, char **argv)
{ 
	t_env env;

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
	return(0);                                              
}