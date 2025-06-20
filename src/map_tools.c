/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:44:28 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/20 18:21:23 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	return (i);
}

char	**copy_map(t_game *game)
{
	char	**new_map;
	int		i;
	int		height;

	height = get_map_height(game->map);
	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_map[i] = ft_strdup(game->map[i]);
		if (!new_map[i])
			return (NULL);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'V')
		return ;
	game->map[y][x] = 'V';
	flood_fill(game->map, x + 1, y);
	flood_fill(game->map, x - 1, y);
	flood_fill(game->map, x, y + 1);
	flood_fill(game->map, x, y - 1);
}

int	find_player(t_game *game, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
