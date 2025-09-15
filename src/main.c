/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:41:46 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/15 11:04:42 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "so_long.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		return (ft_printf("Uso:\n./so_long <map.ber>\n"), 1);
	}
	game.map = map_read(argv[1]);
	if (!game.map)
		return (ft_printf("Error:\n al leer el mapa\n"), 1);
	game.height = get_map_height(game.map);
	game.width = ft_strlen(game.map[0]);
	game.collectibles = count_collectibles(game.map);
	if (!errors(&game))
		return (1);
	game.map[game.player_y][game.player_x] = '0';
	ft_printf("El mapa SÍ es accesible\n");
	game.steps = 0;
	init_window(&game);
	return (0);
}
