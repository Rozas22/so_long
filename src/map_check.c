/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:34:57 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/12 17:44:03 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char	**map)
{
	int	i;
	int	len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	len;
	int	last;

	len = ft_strlen(map[0]);
	last = 0;
	while (map[last])
		last++;
	last--;
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[last][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (map[i < last])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_parameters(char **map)
{
	int			i;
	int			j;
	t_counts	counts;

	counts.p = 0;
	counts.e = 0;
	counts.c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!count_chars(map[i][j], &counts))
				return (0);
			j++;
		}
		i++;
	}
	if (counts.p != 1 || counts.e != 1 || counts.c < 1)
		return (0);
	return (1);
}

static int	count_chars(char c, t_counts *counts)
{
	if (c == 'P')
		counts->p++;
	else if (c == 'E')
		counts->e++;
	else if (c == 'C')
		counts->c++;
	else if (c != 0 && c != 1)
		return (0);
	return (1);
}

int	check_map_accesibility(char **map)
{
	char	**map_copy;
	int		i;
	int		y;

	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	if (!find_player(map_copy, &x, &y))
	{
		free_map(map_copy);
		return(0);
	}
	flood_fill(map_copy, x, y);
	if (!is_map_fully_accessible(map_copy))
	{
		free_map(map_copy);
		return (0);
	}
	free_map(map_copy);
	return (1);
}