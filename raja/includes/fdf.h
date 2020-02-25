/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <ramoukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:23:35 by ramoukha          #+#    #+#             */
/*   Updated: 2020/02/25 15:38:19 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# define SCR_WIDTH 1000
# define SCR_HEIGHT 1000

typedef struct	s_store
{
	int			tab[1000][1000];
	int			w;
	int			h;
}				t_store;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_utils
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			dp;
	int			e2;
	int			c;
}				t_utils;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
}				t_mlx;

typedef struct	s_env
{
	t_mlx		mlx;
	t_store		store;
	int			iso;
	int			h;
	int			v;
	int			up;
	int			x;
	int			y;
}				t_env;

void			ft_error(void);
void			ft_map_debug(t_env *env);
void			ft_free_split(char **tab);
void			ft_print_error(char *s);
void			ft_read_line(t_store *store, int y, char *line);
int				read_file(t_store *store, int fd);
void			ft_store_fdf(t_store *store, char *s);
int				ft_close(void *ptr);
int				ft_key_pressed(int keycode, void *ptr);
void			env_init(t_env *env, char *s);
void			line(t_point start, t_point end, t_env *env);
void			iso(int *x, int *y, int z);
void			manage_values(t_point *start, t_env *env, int x, int y);
void			manage_values3(int x, t_env *env, t_point *start, t_point *end);
void			ft_usage(void);
#endif
