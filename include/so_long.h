/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:55:04 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/27 15:45:01 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft_/libft.h"
# include "../lib/printf_/ft_printf.h"

#define WIDTH 800
#define HEIGHT 600

typedef struct s_counts
{
	int	p;
	int	e;
	int	c;	
}	t_counts;

typedef struct s_game
{
	char	**map;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		width;
	int		height;
	int		steps;
	void	*mlx;
	void	*win;
}	t_game;

char	**map_read(const char *file_path);
int		is_rectangular(t_game *game);
int		check_walls(t_game *game);
int		check_parameters(t_game *game);
char	**copy_map(char	**map);
int		get_map_height(char	**map);
void	free_map(char	**map);
void	flood_fill(char	**map, int x, int y);
int		find_player(char **map, int *x, int *y);
int		is_map_fully_accessible(char **map);
int		check_map_accessibility(t_game *game);
int		find_player_position(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	init_window(t_game *game);

#endif