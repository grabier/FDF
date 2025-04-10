/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:42:02 by gmontoro          #+#    #+#             */
/*   Updated: 2025/01/23 20:31:34 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# define MAX_W 1920  //3840
# define MAX_H 1080  //2160

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

typedef struct s_isopoint
{
	double	ix;
	double	iy;
}				t_isopoint;

typedef struct s_map
{
	char		***matrix;
	int			n_colums;
	int			n_rows;
	int			min_x;
	int			max_x;
	int			min_y;
	int			max_y;
	int			min_z;
	int			max_z;
	int			**i_matrix;
	int			**c_matrix;
	t_point		**p_matrix;
	t_isopoint	**iso_matrix;
}				t_map;

typedef struct s_line
{
	int		x0;
	int		y0;
	int		xf;
	int		yf;
	double	s;
}				t_line;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_data;

//gnl
char		*get_next_line(int fd);
char		*ft_readbuffer(char *buffer, int fd);
char		*ft_joinfree(char *buffer, char *aux);
char		*ft_free(char *buffer);
int			ft_count_rows(char *filename);
int			ft_count_words(const char *s, char c);
void		ft_free_doble(char **s);

t_map		*ft_parse(int argc, char *argv[], int i);
int			ft_get_colums(char *line);
void		ft_bresenham(t_data *data, t_line *l);

//inits
t_isopoint	ft_init_iso_point(t_point p);
t_point		ft_init_point(int x, int y, int z);
t_map		*ft_init_map(char *filename);
t_line		*ft_init_line(t_isopoint p1, t_isopoint p2);
int			**ft_init_int_matrix(t_map *map);
t_point		**ft_init_point_matix(t_map	*map);
t_isopoint	**ft_init_isometric_matix(t_map	*map);
int			**ft_init_color_matrix(t_map *map);
t_isopoint	ft_init_iso_point(t_point p);
void		ft_keyfunc(mlx_key_data_t keydata, void *param);

void		ft_calculate_maxmin(t_map *map, int x, int y);
void		ft_draw_map(t_map *mapa, t_data *data);
t_line		*ft_swap_points(t_line *l);
t_line		*ft_swap_coordinates(t_line *l, int *p);
#endif