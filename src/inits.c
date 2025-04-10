/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:01:54 by gmontoro          #+#    #+#             */
/*   Updated: 2025/01/23 20:29:17 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	*ft_init_map(char *filename)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->n_colums = 0;
	map->n_rows = ft_count_rows(filename);
	map->matrix = (char ***)malloc(sizeof (char **) * (map->n_rows + 1));
	map->max_x = INT_MIN;
	map->max_y = INT_MIN;
	map->min_x = INT_MAX;
	map->min_y = INT_MAX;
	return (map);
}

int	**ft_init_int_matrix(t_map *map)
{
	int	**mat;
	int	i;
	int	j;

	i = 0;
	map->max_z = 0;
	map->min_z = 0;
	mat = (int **)malloc(sizeof(int *) * map->n_rows);
	while (i < map->n_rows)
	{
		j = 0;
		mat[i] = (int *)malloc(sizeof(int) * map->n_colums);
		while (j < map->n_colums)
		{
			mat[i][j] = ft_atoi(map->matrix[i][j]);
			if (mat[i][j] >= map->max_z)
				map->max_z = mat[i][j];
			if (mat[i][j] <= map->min_z)
				map->min_z = mat[i][j];
			j++;
		}
		i++;
	}
	return (mat);
}

t_point	**ft_init_point_matix(t_map	*map)
{
	t_point	**mat;
	int		i;
	int		j;

	i = 0;
	mat = (t_point **)malloc(sizeof(t_point *) * map->n_rows);
	while (i < map->n_rows)
	{
		j = 0;
		mat[i] = (t_point *)malloc(sizeof(t_point) * map->n_colums);
		while (j < map->n_colums)
		{
			mat[i][j] = ft_init_point(i, j, map->i_matrix[i][j]);
			j++;
		}
		i++;
	}
	return (mat);
}

t_isopoint	**ft_init_isometric_matix(t_map	*map)
{
	t_isopoint	**mat;
	int			i;
	int			j;

	i = 0;
	mat = (t_isopoint **) malloc(sizeof(t_isopoint *) * map->n_rows);
	while (i < map->n_rows)
	{
		j = 0;
		mat[i] = (t_isopoint *)malloc(sizeof(t_isopoint) * map->n_colums);
		while (j < map->n_colums)
		{
			mat[i][j] = ft_init_iso_point(map->p_matrix[i][j]);
			ft_calculate_maxmin(map, mat[i][j].ix, mat[i][j].iy);
			j++;
		}
		i++;
	}
	return (mat);
}

int	**ft_init_color_matrix(t_map *map)
{
	int		**mat;
	int		i;
	int		j;
	char	**sp;

	i = 0;
	mat = (int **)malloc(sizeof(int *) * map->n_rows);
	while (i < map->n_rows)
	{
		j = 0;
		mat[i] = (int *)malloc(sizeof(int) * map->n_colums);
		while (j < map->n_colums)
		{
			sp = ft_split(map->matrix[i][j], ',');
			if (!sp[1])
				mat[i][j] = 0xFFFFFFFF;
			else
				mat[i][j] = ft_atoi(sp[1]);
			ft_free_doble(sp);
			j++;
		}
		i++;
	}
	return (mat);
}
