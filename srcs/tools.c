/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <ramoukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:12:39 by ramoukha          #+#    #+#             */
/*   Updated: 2020/01/09 15:53:24 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void		ft_usage(void)
{
	ft_putendl("Usage: ./fdf [map]");
	exit(0);
}

void		ft_print_error(char *s)
{
	ft_putendl(s);
	exit(EXIT_FAILURE);
}

void		ft_free_split(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
}

void		ft_error(void)
{
	perror("Error");
	exit(-1);
}

void		menu(t_mlx mlx)
{
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_win, 100, 820, 0xFFFF, "MENU");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_win, 20, 850, 0xFFFF, "P : PROJECTION");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_win, 20, 880, 0xFFFF, "+/- : ZOOM");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_win,\
			20, 910, 0xFFFF, "PAGE UP/DOWN : ALTITUDE");
	mlx_string_put(mlx.mlx_ptr, mlx.mlx_win,\
			20, 940, 0xFFFF, "ARROWS : MOVEMENTS");
}
