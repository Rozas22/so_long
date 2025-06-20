/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:37:46 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/20 18:55:56 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] != '1')
	{
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		game->player_y--;
		game->steps++;
		ft_printf("Movements: %d\n", game->steps);
	}
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_x;
	if (game->map[y + 1][x] != '1')
	{
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		game->player_y++;
		game->steps++;
		ft_printf("Movements: %d\n", game->steps);
	}
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] != '1')
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		game->player_x--;
		game->steps++;
		ft_printf("Movements: %d\n", game->steps);
	}
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] != '1')
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		game->player_x++;
		game->steps++;
		ft_printf("Movements: %d\n", game->steps);
	}
}
