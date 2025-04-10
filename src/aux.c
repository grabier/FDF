/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:44:20 by gmontoro          #+#    #+#             */
/*   Updated: 2025/01/23 19:01:07 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_free_doble(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	ft_count_words(const char *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c && s[0] != '\0')
		cont++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0' && s[i + 1] != '\n')
			cont++;
		i++;
	}
	if (cont == 0 && s[i - 1] != c)
		return (1);
	return (cont);
}

int	ft_get_colums(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i / 2);
}

int	ft_count_rows(char *filename)
{
	int		bytes;
	int		fd;
	char	buffer[1];
	int		cont;

	bytes = 0;
	buffer[0] = 'c';
	cont = 0;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes <= 0)
			break ;
		if (buffer[0] == '\n' || buffer[0] == EOF)
			cont++;
	}
	if (buffer[0] == '0')
		cont++;
	close(fd);
	return (cont);
}

t_point	ft_init_point(int x, int y, int z)
{
	t_point	p;

	p.x = y;
	p.y = x;
	p.z = z;
	return (p);
}
