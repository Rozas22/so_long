/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:55:04 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/05 11:50:17 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"

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

#endif