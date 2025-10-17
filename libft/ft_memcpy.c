/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:08:46 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/04/26 09:58:06 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*temp2;

	i = 0;
	temp = dest;
	temp2 = (unsigned char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		temp[i] = temp2[i];
		i++;
	}
	dest = (void *)temp;
	src = (const void *)temp2;
	return (dest);
}
