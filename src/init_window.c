/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:25:45 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/11 17:27:53 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"

void	render_hook(void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	mlx_image_to_window(game->mlx, game->img_floor,
		x * TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->img_wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (x == game->player_x && y == game->player_y)
		mlx_image_to_window(game->mlx, game->img_player,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_image_to_window(game->mlx, game->img_exit,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_image_to_window(game->mlx, game->img_collectible,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS)
		return ;

	if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_W
		|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_A
		|| keydata.key == MLX_KEY_D)
		move(game, ((keydata.key == MLX_KEY_D) - (keydata.key == MLX_KEY_A)),
			((keydata.key == MLX_KEY_S) - (keydata.key == MLX_KEY_W)));
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init(game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long", false);
	if (!game->mlx)
		exit(1);
	if (load_textures(game) || load_maptextures(game))
	{
		ft_printf("Error\n cargando texturas\n");
		mlx_terminate(game->mlx);
		exit(EXIT_FAILURE);
	}
	render_hook(game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
