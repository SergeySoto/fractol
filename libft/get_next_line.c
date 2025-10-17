/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:35:52 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/04 18:30:07 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get__line(int fd, char *line)
{
	int		ch_read;
	char	*buf;

	if (!line)
		line = ft_strdup_gnl("");
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || !line)
		return (NULL);
	ch_read = 1;
	while (ch_read > 0 && ft_strchr_gnl(line, '\n') == NULL)
	{
		ch_read = read(fd, buf, BUFFER_SIZE);
		if (ch_read < 0)
		{
			free(buf);
			free(line);
			line = NULL;
			return (NULL);
		}
		buf[ch_read] = '\0';
		line = ft_strjoin_gnl(line, buf);
	}
	free(buf);
	return (line);
}

char	*cut__line(char *line)
{
	int		i;
	char	*aux;

	i = 0;
	if (!line || !line[0])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	aux = ft_substr_gnl(line, 0, i);
	if (!aux)
	{
		free(aux);
		return (NULL);
	}
	return (aux);
}

char	*update_static(char *line)
{
	char	*rest;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	rest = ft_substr_gnl(line, i, ft_strlen_gnl(line + i, '\0'));
	free(line);
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(line);
		return (NULL);
	}
	line = get__line(fd, line);
	if (!line || line[0] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	new_line = cut__line(line);
	if (!new_line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = update_static(line);
	return (new_line);
}
