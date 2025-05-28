/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:21:53 by iker              #+#    #+#             */
/*   Updated: 2025/04/30 16:52:58 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*temp;
	size_t	i;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	line = ft_substr(*buffer, 0, i + 1);
	temp = ft_strdup(*buffer + i + (i < ft_strlen(*buffer)));
	free(*buffer);
	*buffer = temp;
	return (line);
}

static int	read_into_buffer(int fd, char **buffer)
{
	char	*temp;
	char	*buf;
	int		bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		temp = ft_strjoin(*buffer, buf);
		free(*buffer);
		*buffer = temp;
		if (ft_strchr(*buffer, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	bytes_read = read_into_buffer(fd, &buffer);
	if (bytes_read < 0 || (bytes_read == 0 && !*buffer))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (extract_line(&buffer));
}
