/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:25:45 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/27 14:42:56 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>

void	init_window(t_game *game)
{
	gmae->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game->mlx)
	{
		ft_printf("Error iniciando MLX: %s\n", ,mlx_strerror(mlx_errno));
		EXIT(EXIT_FAILURE);
	}
}
