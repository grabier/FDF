/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:41:34 by gmontoro          #+#    #+#             */
/*   Updated: 2025/01/23 20:30:44 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
//10 functions

int	ft_calculate_factor(t_map *map, int mode)
{
	if (mode == 1)
		return (550 / map->n_rows);
	if ((map->max_z - map->min_z) / map->n_rows == 0 && map->n_rows > 100)
	{
		if (mode == 0)
			return (1000 / map->n_colums);
		else
			return (500 / map->n_rows);
	}
	else if ((map->max_z - map->min_z) / map->n_colums <= 1)
	{
		if (mode == 0)
			return (1000 / map->n_colums);
		else
			return (300 / map->n_rows);
	}
	else
	{
		if (mode == 0)
			return (800 / map->n_colums);
		else
			return (50 / map->n_rows);
	}
}

t_point	**ft_scale_point_matrix(t_map	*map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->n_rows)
	{
		j = 0;
		while (j < map->n_colums)
		{
			map->p_matrix[i][j].x *= ft_calculate_factor(map, 0);
			map->p_matrix[i][j].y *= ft_calculate_factor(map, 1);
			map->p_matrix[i][j].z *= ft_calculate_factor(map, 2);
			j++;
		}
		i++;
	}
	return (map->p_matrix);
}

void	ft_draw_line(t_data *data, t_isopoint p1, t_isopoint p2)
{
	t_line	*l;

	l = ft_init_line(p1, p2);
	ft_bresenham(data, l);
	free(l);
}

void	ft_draw_map(t_map *m, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->n_rows - 1)
	{
		j = 0;
		while (j < m->n_colums - 1)
		{
			ft_draw_line(data, m->iso_matrix[i][j], m->iso_matrix[i + 1][j]);
			ft_draw_line(data, m->iso_matrix[i][j], m->iso_matrix[i][j + 1]);
			j++;
		}
		i++;
	}
	j = -1;
	while (++j < m->n_colums - 1)
		ft_draw_line(data, m->iso_matrix[i][j], m->iso_matrix[i][j + 1]);
	i = -1;
	while (++i < m->n_rows - 1)
		ft_draw_line(data, m->iso_matrix[i][j], m->iso_matrix[i + 1][j]);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

t_map	*ft_parse(int argc, char *argv[], int i)
{
	t_map	*map;
	int		fd;
	char	*line;

	if (argc != 2)
		return (NULL);
	map = ft_init_map(argv[1]);
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->n_colums = ft_count_words(line, ' ');
		map->matrix[i++] = ft_split(line, ' ');
		free(line);
	}
	map->i_matrix = ft_init_int_matrix(map);
	map->p_matrix = ft_init_point_matix(map);
	map->p_matrix = ft_scale_point_matrix(map);
	map->iso_matrix = ft_init_isometric_matix(map);
	return (map);
}
