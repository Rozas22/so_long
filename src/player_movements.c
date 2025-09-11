/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:37:46 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/11 17:25:41 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, int mx, int my)
{
	int	x;
	int	y;

	x = game->player_x + mx;
	y = game->player_y + my;
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'E' && game->collectibles == 0)
	{
		free_map(game->map);
		ft_printf("¡Ganaste en %d movimientos!\n", game->steps + 1);
		mlx_close_window(game->mlx);
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->collectibles--;
	}
	game->player_x = x;
	game->player_y = y;
	game->steps++;
	ft_printf("Movements: %d\n", game->steps);
	render_hook(game);
}
