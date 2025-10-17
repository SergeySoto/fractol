/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:17:22 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/14 19:44:56 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1s2;
	char	*str;

	len_s1s2 = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc(len_s1s2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1s2 + 1);
	ft_strlcat(str, s2, len_s1s2 + 1);
	return (str);
}
