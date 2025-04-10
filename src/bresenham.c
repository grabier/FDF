/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:47:37 by gmontoro          #+#    #+#             */
/*   Updated: 2025/01/23 20:35:50 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_calculate_maxmin(t_map *map, int x, int y)
{
	if (map->max_x < x)
		map->max_x = x;
	if (map->min_x > x)
		map->min_x = x;
	if (map->max_y < y)
		map->max_y = y;
	if (map->min_y > y)
		map->min_y = y;
}

static void	ft_case1(t_data *data, t_line *l, int *i, int *j)
{
	int	p;
	int	x;
	int	y;

	x = *i;
	y = *j;
	p = 2 * (l->yf - l->y0) - (l->xf - l->x0);
	while (x < l->xf && y <= l->yf)
	{
		if (p <= 0 && x++ < l->xf)
			p = p + 2 * (l->yf - l->y0);
		else if (x++ < l->xf && y++ <= l->yf)
			p = p + 2 * (l->yf - l->y0) - 2 * (l->xf - l->x0);
		mlx_put_pixel(data->img, x, y, 0xFFFFFFFF);
	}
	*i = x;
	*j = y;
}

static void	ft_case2(t_data *data, t_line *l, int *i, int *j)
{
	int	p;
	int	x;
	int	y;

	x = *i;
	y = *j;
	p = 2 * (l->yf - l->y0) - (l->xf - l->x0);
	l->y0 = l->y0 * -1;
	l->yf = l->yf * -1;
	y = l->y0;
	while (x < l->xf && y <= l->yf)
	{
		if (p < 0 && x++ < l->xf)
			p = p + 2 * (l->yf - l->y0);
		else if (x++ < l->xf && y++ <= l->yf)
			p = p + 2 * (l->yf - l->y0) - 2 * (l->xf - l->x0);
		mlx_put_pixel(data->img, x, -y, 0xFFFFFFFF);
	}
	*i = x;
	*j = y;
}

static void	ft_case3(t_data *data, t_line *l, int *i, int *j)
{
	int	p;
	int	x;
	int	y;

	if (l->s <= -1)
	{
		l->y0 = l->y0 * -1;
		l->yf = l->yf * -1;
	}
	l = ft_swap_coordinates(l, &p);
	x = l->x0;
	y = l->y0;
	while (x < l->xf && y <= l->yf)
	{
		if (p <= 0 && x++ < l->xf)
			p = p + 2 * (l->yf - l->y0);
		else if (x++ < l->xf && y++ <= l->yf)
			p = p + 2 * (l->yf - l->y0) - 2 * (l->xf - l->x0);
		if (l->s > -1)
			mlx_put_pixel(data->img, y, x, 0xFFFFFFFF);
		else
			mlx_put_pixel(data->img, y, -x, 0xFFFFFFFF);
	}
	*i = x;
	*j = y;
}

void	ft_bresenham(t_data *data, t_line *l)
{
	int	i;
	int	j;

	if (l->x0 > l->xf)
		l = ft_swap_points(l);
	mlx_put_pixel(data->img, i = l->x0, j = l->y0, 0xFFFFFFFF);
	if (l->s >= 0 && l->s < 1)
		ft_case1(data, l, &i, &j);
	else if (l->s < 0 && l->s > -1)
		ft_case2(data, l, &i, &j);
	else if (l->s >= 1 || l->s <= -1)
		ft_case3(data, l, &i, &j);
}
