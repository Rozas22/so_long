/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:25:45 by ikrozas           #+#    #+#             */
/*   Updated: 2025/07/08 20:59:28 by ikrozas          ###   ########.fr       */
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
	/*if (tile == '1' && !game->img_wall)
		ft_printf("img_wall es NULL en (%d,%d)\n", x, y);
	if (tile == 'P' && !game->img_player)
		ft_printf("img_player es NULL en (%d,%d)\n", x, y);
	if (tile == 'C' && !game->img_collectible)
		ft_printf("img_collectible es NULL en (%d,%d)\n", x, y);
	if (tile == 'E' && !game->img_exit)
		ft_printf("img_exit es NULL en (%d,%d)\n", x, y);*/
	mlx_image_to_window(game->mlx, game->img_floor,
		x * TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->img_wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
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
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W)
		move_up(game);
	else if (keydata.key == MLX_KEY_S)
		move_down(game);
	else if (keydata.key == MLX_KEY_A)
		move_left(game);
	else if (keydata.key == MLX_KEY_D)
		move_right(game);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init(game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long", false);
	if (!game->mlx)
		exit(1);
	if (load_textures(game) || load_maptextures(game))
	{
		ft_printf("Error cargando texturas\n");
		mlx_terminate(game->mlx);
		exit(EXIT_FAILURE);	
	}
	render_hook(game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
