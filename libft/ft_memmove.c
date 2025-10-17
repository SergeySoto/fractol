/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:15:30 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/04/29 19:30:28 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	temp_dest = dest;
	temp_src = (unsigned char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (temp_dest > temp_src)
	{
		while (n > 0)
		{
			n--;
			temp_dest[n] = temp_src[n];
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest = (void *)temp_dest);
}
