/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:55:04 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/20 18:58:14 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft_/libft.h"
# include "../lib/printf_/ft_printf.h"

typedef struct s_counts
{
	int	p;
	int	e;
	int	c;	
}	t_counts;

char	**map_read(const char *file_path);
int		is_rectangular(t_game *game);
int		check_walls(t_game *game);
int		check_parameters(t_game *game);
char	**copy_map(t_game *game);
int		get_map_height(t_game *game);
void	free_map(t_game *game);
void	flood_fill(t_game *game, int x, int y);
int		find_player(t_game *game, int *x, int *y);
int		is_map_fully_accessible(t_game *game);
int		check_map_accessibility(t_game *game);
void	print_map_debug(t_game *game);
int		find_player_position(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);

typedef struct s_game
{
	char	**map;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		width;
	int		height;
	int		steps;	
}	t_game;

#endif