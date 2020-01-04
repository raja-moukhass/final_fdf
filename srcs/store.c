/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <ramoukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:20:39 by ramoukha          #+#    #+#             */
/*   Updated: 2020/01/03 15:28:21 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	ft_print_store(t_store *store)
{
	int		i;
	int		j;

	i = -1;
	while (++i < store->h)
	{
		j = -1;
		while (++j < store->w)
			printf("%2d ", store->tab[i][j]);
		printf("\n");
	}
}

void	ft_read_line(t_store *store, int y, char *line)
{
	char	**split;
	int		x;

	x = -1;
	split = ft_strsplit(line, ' ');
	while (split[++x] != NULL)
		store->tab[y][x] = ft_atoi(split[x]);
	ft_free_split(split);
	if (!x || ((x && store->w) && (x < store->w)))
		ft_print_error("bad map length");
	if (!store->w)
		store->w = x;
}

int		read_file(t_store *store, int fd)
{
	char *line;
	int y;

	y = 0;
	if (get_next_line(fd, &line) == 1 && line != NULL)
		ft_read_line(store, y++, line);
	else
		ft_error();
	free(line);
	while (get_next_line(fd, &line) == 1 && line != NULL)
	{
		ft_read_line(store, y++, line);
		free(line);
	}
	store->h = y;
	ft_print_store(store);
	return (0);
}

void	ft_store_fdf(t_store *store, char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	read_file(store, fd);
	close(fd);
}
