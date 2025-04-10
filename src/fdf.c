/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:07:10 by gmontoro          #+#    #+#             */
/*   Updated: 2025/01/23 20:35:07 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_line	*ft_swap_points(t_line *l)
{
	int	aux;

	aux = l->x0;
	l->x0 = l->xf;
	l->xf = aux;
	aux = l->y0;
	l->y0 = l->yf;
	l->yf = aux;
	if (l->xf == l->x0)
		l->s = 2;
	else
		l->s = (double)(l->yf - l->y0) / (double)(l->xf - l->x0);
	return (l);
}

t_line	*ft_swap_coordinates(t_line *l, int *p)
{
	int	aux;

	aux = l->x0;
	l->x0 = l->y0;
	l->y0 = aux;
	aux = l->xf;
	l->xf = l->yf;
	l->yf = aux;
	*p = 2 * (l->yf - l->y0) - (l->xf - l->x0);
	return (l);
}

t_line	*ft_init_line(t_isopoint p1, t_isopoint p2)
{
	t_line	*l;

	l = malloc(sizeof(t_line));
	l->x0 = (int)p1.ix;
	l->xf = (int)p2.ix;
	l->y0 = (int)p1.iy;
	l->yf = (int)p2.iy;
	if (l->xf == l->x0)
		l->s = 2;
	else
		l->s = (double)(l->yf - l->y0) / (double)(l->xf - l->x0);
	return (l);
}

static void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->n_rows)
	{
		ft_free_doble(map->matrix[i]);
		free(map->iso_matrix[i]);
		free(map->i_matrix[i]);
		free(map->p_matrix[i]);
		i++;
	}
	free(map->i_matrix);
	free(map->matrix);
	free(map->iso_matrix);
	free(map->p_matrix);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_map	*mapa;

	mapa = ft_parse(argc, argv, 0);
	if (!mapa)
		return (7);
	data.mlx = mlx_init(MAX_W, MAX_H, "Hello world!", 1);
	data.img = mlx_new_image(data.mlx, MAX_W, MAX_H);
	ft_draw_map(mapa, &data);
	mlx_key_hook(data.mlx, &ft_keyfunc, data.mlx);
	mlx_loop(data.mlx);
	ft_free_map(mapa);
	free(mapa);
	mlx_delete_image(data.mlx, data.img);
	mlx_terminate(data.mlx);
	return (0);
}
