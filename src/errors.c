/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:55:03 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/15 10:42:44 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	errors(t_game *game)
{
	if (!is_rectangular(game))
		return (ft_printf("Error:\nEl mapa no es rectangular\n"), 0);
	if (!check_walls(game))
		return(ft_printf("Error\nFalta algun muro\n"), 0);
	if (!check_parameters(game) || !find_player_position(game))
		return (ft_printf("Error:\nFalta algun elemento\n"), 0);
	if (!check_map_accessibility(game))
		return (ft_printf("Error:\nEl mapa NO es accesible\n"), 0);
	return (1);
}
