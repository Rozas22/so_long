/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:37:46 by ikrozas           #+#    #+#             */
/*   Updated: 2025/07/08 21:13:19 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] == '1')
		return ;
	if (game->map[y - 1][x] == 'E')
	{
		if (game->collectibles == 0)
		{
			ft_printf("¡Ganaste en %d movimientos!\n", game->steps + 1);
			mlx_close_window(game->mlx);
		}
		return ;
	}
	if (game->map[y - 1][x] == 'C')
		game->collectibles--;
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'P';
	game->player_y--;
	game->steps++;
	ft_printf("Movements: %d\n", game->steps);
	game->img_player->instances[0].x = game->player_x * TILE_SIZE;
	game->img_player->instances[0].y = game->player_y * TILE_SIZE;
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] == '1')
		return ;
	if (game->map[y + 1][x] == 'E')
	{
		if (game->collectibles == 0)
		{
			ft_printf("¡Ganaste en %d movimientos!\n", game->steps + 1);
			mlx_close_window(game->mlx);
		}
		return ;
	}
	if (game->map[y + 1][x] == 'C')
		game->collectibles--;
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'P';
	game->player_y++;
	game->steps++;
	ft_printf("Movements: %d\n", game->steps);
	game->img_player->instances[0].x = game->player_x * TILE_SIZE;
	game->img_player->instances[0].y = game->player_y * TILE_SIZE;
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] == '1')
		return ;
	if (game->map[y][x - 1] == 'E')
	{
		if (game->collectibles == 0)
		{
			ft_printf("¡Ganaste en %d movimientos!\n", game->steps + 1);
			mlx_close_window(game->mlx);
		}
		return ;
	}
	if (game->map[y][x - 1] == 'C')
		game->collectibles--;
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'P';
	game->player_x--;
	game->steps++;
	ft_printf("Movements: %d\n", game->steps);
	game->img_player->instances[0].x = game->player_x * TILE_SIZE;
	game->img_player->instances[0].y = game->player_y * TILE_SIZE;
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] == '1')
		return ;
	if (game->map[y][x + 1] == 'E')
	{
		if (game->collectibles == 0)
		{
			ft_printf("¡Ganaste en %d movimientos!\n", game->steps + 1);
			mlx_close_window(game->mlx);
		}
		return ;
	}
	if (game->map[y][x + 1] == 'C')
		game->collectibles--;
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'P';
	game->player_x++;
	game->steps++;
	ft_printf("Movements: %d\n", game->steps);
	game->img_player->instances[0].x = game->player_x * TILE_SIZE;
	game->img_player->instances[0].y = game->player_y * TILE_SIZE;
}
