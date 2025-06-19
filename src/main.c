/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:41:46 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/18 11:30:28 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
	{
		ft_printf("Uso: ./so_long <map.ber>\n");
		return (1);
	}
	map = map_read(argv[1]);
	if (!map)
		return (ft_printf("Error al leer el mapa\n"), 1);
	if (!is_rectangular)
		return (ft_printf("El mapa no es rectangular\n"), 1);
	ft_printf("Mapa válido\n");
	return (0);
}*/
int	main(void)
{
	char *map[] = {
		"11111",
		"1P001",
		"100E1",
		"11111",
		NULL
	};
	if (!check_map_accessibility(map))
		ft_printf("El mapa NO es accesible\n");
	else
	ft_printf("El mapa SÍ es accesible\n");
	return (0);
}

