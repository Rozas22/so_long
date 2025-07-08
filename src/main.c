/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:41:46 by ikrozas           #+#    #+#             */
/*   Updated: 2025/07/08 19:24:44 by ikrozas          ###   ########.fr       */
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
		ft_printf("Uso: ./so_long <map.ber>\n");
		return (1);
	}
	game.map = map_read(argv[1]);
	if (!game.map)
		return (ft_printf("Error al leer el mapa\n"), 1);
	game.height = get_map_height(game.map);
	game.width = ft_strlen(game.map[0]);
	if (!check_map_accessibility(&game))
		return (ft_printf("El mapa NO es accesible\n"), 1);
	ft_printf("El mapa SÍ es accesible\n");
	game.steps = 0;
	init_window(&game);
	return (0);
}
