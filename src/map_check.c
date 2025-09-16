/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:34:57 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/16 18:17:44 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_game *game)
{
	int	i;
	int	len;

	if (!game->map || !game->map[0])
		return (0);
	len = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	i;
	int	len;
	int	last;

	len = ft_strlen(game->map[0]);
	last = 0;
	while (game->map[last])
		last++;
	last--;
	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' || game->map[last][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < last)
	{
		if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
			return (0);
		i++;
	}
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
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}

int	check_parameters(t_game *game)
{
	int			i;
	int			j;
	t_counts	counts;

	counts.p = 0;
	counts.e = 0;
	counts.c = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!count_chars(game->map[i][j], &counts))
				return (0);
			j++;
		}
		i++;
	}
	if (counts.p != 1 || counts.e != 1 || counts.c < 1)
		return (0);
	return (1);
}

int	check_map_accessibility(t_game *game)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = copy_map(game->map);
	if (!map_copy)
		return (0);
	if (!find_player(map_copy, &x, &y))
	{
		free_map(map_copy);
		return (0);
	}
	flood_fill(map_copy, x, y, game->width, game->height);
	if (!is_map_fully_accessible(map_copy))
	{
		free_map(map_copy);
		return (0);
	}
	free_map(map_copy);
	return (1);
}
