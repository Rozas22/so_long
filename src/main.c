/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:41:46 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/20 18:43:10 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!check_map_accessibility(&game))
		return (ft_printf("El mapa NO es accesible\n"), 1);
	ft_printf("El mapa SÍ es accesible\n");
	game.steps = 0;
	return (0);
}
/*int	main(void)
{
	char *map[] = {
		"11111",
		"1P001",
		"10101",
		"11E11"
		"11111",
		NULL
	};
	if (!check_map_accessibility(map))
		ft_printf("El mapa NO es accesible\n");
	else
	ft_printf("El mapa SÍ es accesible\n");
	return (0);
}*/
