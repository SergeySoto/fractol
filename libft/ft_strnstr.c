/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:21:56 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/05/06 16:24:24 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)&big[i]);
	while (big[i] != '\0' && i < len)
	{
		n = 0;
		while (little[n] != '\0' && big[i + n] == little[n] && i + n < len)
			n++;
		if (little[n] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
