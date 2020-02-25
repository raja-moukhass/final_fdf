/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <ramoukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:47:39 by ramoukha          #+#    #+#             */
/*   Updated: 2020/02/25 15:37:05 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	env_init(t_env *env, char *s)
{
	ft_store_fdf(&env->store, s);
	env->mlx.mlx_ptr = mlx_init();
	env->mlx.mlx_win = mlx_new_window(env->mlx.mlx_ptr, 1000, 1000, "FDF");
}

int		ft_close(void *ptr)
{
	t_env	*env;

	env = (t_env*)ptr;
	mlx_clear_window(env->mlx.mlx_ptr, env->mlx.mlx_win);
	exit(EXIT_SUCCESS);
	return (1);
}

int		ft_key_pressed(int keycode, void *ptr)
{
	t_env	*env;

	env = (t_env *)ptr;
	if (keycode == 53)
		ft_close(env);
	if (keycode == 78)
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
	return (1);
}
