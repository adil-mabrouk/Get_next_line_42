/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:42:33 by amabrouk          #+#    #+#             */
/*   Updated: 2023/12/20 17:27:17 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_next(char *var)
{
	char	*string;
	int		i;

	if (!var)
		return (free(var), NULL);
	i = 0;
	while (var[i] && var[i] != '\n')
		i++;
	if (var[i] == '\n')
		i++;
	string = ft_strdup(var + i);
	return (free(var), string);
}

char	*ft_get_line(char *var)
{
	int		i;
	char	*line;

	if (!var)
		return (free(var), NULL);
	i = 0;
	while (var[i] && var[i] != '\n')
		i++;
	if (var[i] == '\n')
		i++;
	line = ft_substr(var, 0, i);
	return (line);
}

char	*ft_read(int fd, char *buffer, char *var)
{
	int	r_bytes;

	r_bytes = 1;
	while (r_bytes > 0 && !ft_strchr(var, '\n'))
	{
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes == -1)
			return (free(var), free(buffer), NULL);
		buffer[r_bytes] = 0;
		var = ft_strjoin(var, buffer);
	}
	free(buffer);
	if (var && !var[0])
		return (free(var), NULL);
	return (var);
}

char	*get_next_line(int fd)
{
	static char	*var[OPEN_MAX];
	char		*buffer;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (10 <= 0 || BUFFER_SIZE > INT_MAX)
		return (free(var[fd]), var[fd] = NULL, NULL);
	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (free(var[fd]), var[fd] = NULL, NULL);
	var[fd] = ft_read(fd, buffer, var[fd]);
	if (!var[fd])
		return (NULL);
	line = ft_get_line(var[fd]);
	if (!line)
	{
		free(var[fd]);
		var[fd] = NULL;
	}
	var[fd] = ft_get_next(var[fd]);
	return (line);
}
