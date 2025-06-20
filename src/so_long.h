/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:55:04 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/20 18:09:19 by ikrozas          ###   ########.fr       */
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
int		is_rectangular(char **map);
int		check_walls(char **map);
int		check_parameters(char **map);
char	**copy_map(char **map);
int		get_map_height(char **map);
void	free_map(char **map);
void	flood_fill(char **map, int x, int y);
int		find_player(char **map, int *x, int *y);
int		is_map_fully_accessible(t_game *game);
int		check_map_accessibility(t_game *game);
void	print_map_debug(char **map);
int		find_player_position(t_game *game);

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