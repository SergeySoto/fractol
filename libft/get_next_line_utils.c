/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:37:56 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/06/09 17:48:10 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*result;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	result = (char *)malloc((sizeof(char)) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size_s;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	size_s = ft_strlen_gnl(s, '\0');
	if (len > size_s - start)
		len = size_s - start;
	if (start > size_s)
		return (malloc(1 * sizeof(char)));
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *line, char *buf)
{
	int		len_linebuf;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len_linebuf = ft_strlen_gnl(line, '\0') + ft_strlen_gnl(buf, '\0');
	str = malloc((len_linebuf + 1 * sizeof(char)));
	if (!str)
		return (NULL);
	while (line[i] != '\0')
	{
		str[i] = line[i];
		i++;
	}
	while (buf[j] != '\0')
	{
		str[i + j] = buf[j];
		j++;
	}
	str[i + j] = '\0';
	free(line);
	return (str);
}
