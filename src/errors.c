/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:55:03 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/16 19:11:56 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argv(int ac, char **av)
{
	char	*extension;
	int		len_str;
	int		result;

	if (ac < 2)
		ft_printf("Error:\nYou have to include a map\n", 0);
	else if (ac > 2)
		ft_printf("Error:\nToo many arguments.", 0);
	else
	{
		len_str = ft_strlen(av[1]);
		extension = ft_substr(av[1], len_str - 4, 4);
		result = ft_strncmp(extension, ".ber", 4);
		free(extension);
		if (result != 0)
			ft_printf("Error:\nIncorrect extension (.ber)\n", 0);
		extension = ft_substr(av[1], len_str - 5, 5);
		result = ft_strncmp(extension, "/.ber", 5);
		free(extension);
		if (result == 0)
			ft_printf("Error:\nfile without name\n", 0);
	}
}

int	errors(t_game *game)
{
	if (!is_rectangular(game))
		return (ft_printf("Error:\nThe map is not rectangular\n"), 0);
	if (!check_walls(game))
		return(ft_printf("Error\nA wall is missing\n"), 0);
	if (!check_parameters(game) || !find_player_position(game))
		return (ft_printf("Error:\nIs a missing element\n"), 0);
	if (!check_map_accessibility(game))
		return (ft_printf("Error:\nThe map is not accesible\n"), 0);
	return (1);
}
