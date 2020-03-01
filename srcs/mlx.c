/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:13:15 by ramoukha          #+#    #+#             */
/*   Updated: 2020/01/09 15:54:16 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	env_init(t_env *env, char *s)
{
	env->mlx.mlx_ptr = mlx_init();
	env->mlx.mlx_win = mlx_new_window(env->mlx.mlx_ptr, SCR_WIDTH, SCR_HEIGHT,
			"FDF");
	ft_store_fdf(&env->store, s);
	env->h = SCR_WIDTH / 2 > env->store.w * env->zoom / 2 ?\
	SCR_WIDTH / 2 - env->store.w * env->zoom / 2 : 0;
	env->v = SCR_HEIGHT / 2 > env->store.h * env->zoom / 2 ?\
	SCR_HEIGHT / 2 - env->store.h * env->zoom / 2 : 0;
	env->u = (t_point){100, 200, 0};
}

int		ft_key_pressed(int keycode, void *ptr)
{
	t_env	*env;

	env = (t_env *)ptr;
	(keycode == 53) ? ft_close(env) : 0;
	if (keycode == 78)
		env->zoom > 1 ? env->zoom -= 1 : 0;
	keycode == 69 ? env->zoom += 1 : 0;
	if (keycode == 35)
		env->iso = env->iso == 0 ? 1 : 0;
	if (keycode == 124)
		env->h += 10;
	if (keycode == 123)
		env->h -= 10;
	if (keycode == 125)
		env->v += 10;
	if (keycode == 126)
		env->v -= 10;
	if (keycode == 116)
		env->up += 1;
	if (keycode == 121)
		env->up -= 1;
	mlx_clear_window(env->mlx.mlx_ptr, env->mlx.mlx_win);
	ft_map_debug(env);
	menu(env->mlx);
	return (1);
}

int		ft_close(void *ptr)
{
	t_env	*env;

	env = (t_env*)ptr;
	mlx_clear_window(env->mlx.mlx_ptr, env->mlx.mlx_win);
	exit(EXIT_SUCCESS);
	return (1);
}
