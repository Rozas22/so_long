/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:54:01 by ikrozas           #+#    #+#             */
/*   Updated: 2025/07/08 20:30:13 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"

int	load_maptextures(t_game *game)
{
	mlx_texture_t	*textu;

	textu = mlx_load_png("textures/wall100x100.png");
	if (!textu)
		return (1);
	game->img_wall = mlx_texture_to_image(game->mlx, textu);
	mlx_delete_texture(textu);
	if (!game->img_wall)
		return (1);
	textu = mlx_load_png("textures/floor100x100.png");
	if (!textu)
		return (1);
	game->img_floor = mlx_texture_to_image(game->mlx, textu);
	mlx_delete_texture(textu);
	if (!game->img_floor)
		return (1);
	return (0);
}

int	load_textures(t_game *game)
{
	mlx_texture_t	*textu;

	textu = mlx_load_png("textures/frodo.png");
	if (!textu)
		return (1);
	game->img_player = mlx_texture_to_image(game->mlx, textu);
	mlx_delete_texture(textu);
	if (!game->img_player)
		return (1);
	textu = mlx_load_png("textures/anillo.png");
	if (!textu)
		return (1);
	game->img_collectible = mlx_texture_to_image(game->mlx, textu);
	mlx_delete_texture(textu);
	if (!game->img_collectible)
		return (1);
	textu = mlx_load_png("textures/exit.png");
	if (!textu)
		return (1);
	game->img_exit = mlx_texture_to_image(game->mlx, textu);
	mlx_delete_texture(textu);
	if (!game->img_exit)
		return (1);
	return (0);
}
