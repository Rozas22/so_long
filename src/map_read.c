/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:13:20 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/10 13:01:52 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_read(const char	*file_path)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * 10000);
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	remove_newline(line);
	while (line || i < 9999)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	remove_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
}

int	count_collectibles(char **map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
