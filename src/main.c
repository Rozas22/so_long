/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:41:46 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/16 19:08:15 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "so_long.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_game	game;

	check_argv(argc, argv);
	game.map = map_read(argv[1]);
	if (!game.map)
		return (ft_printf("Error:\nreading the map\n"), 1);
	game.height = get_map_height(game.map);
	game.width = ft_strlen(game.map[0]);
	game.collectibles = count_collectibles(game.map);
	if (!errors(&game))
		return (free_map(game.map), 1);
	game.map[game.player_y][game.player_x] = '0';
	ft_printf("The map is accesible\n");
	game.steps = 0;
	init_window(&game);
	return (0);
}
