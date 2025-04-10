/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:07:07 by gmontoro          #+#    #+#             */
/*   Updated: 2025/01/23 20:31:23 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_joinfree(char *buffer, char *aux)
{
	char	*temp;

	temp = ft_strjoin(buffer, aux);
	free(buffer);
	return (temp);
}

t_isopoint	ft_init_iso_point(t_point p)
{
	t_isopoint	ip;

	ip.ix = ((p.x - p.y) * 0.87) + 800;
	ip.iy = (-p.z + (p.x + p.y) * 0.53) + 200;
	return (ip);
}

void	ft_keyfunc(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window((mlx_t *)param);
}
