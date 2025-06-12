/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:13:20 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/12 17:01:02 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_read(const char	*file_path)
{
	int		fd;
	char	**map;
	char	**line;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * 10000);
	if (!map)
		return (NULL);
	i = 0;
	while (line || i < 9999)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
