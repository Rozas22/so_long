/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:44:28 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/12 17:01:27 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**copy_map(char **map)
{
	char	**new_map;
	int		i;
	int		height;

	height = get_map_height(map);
	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
			return (NULL);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
