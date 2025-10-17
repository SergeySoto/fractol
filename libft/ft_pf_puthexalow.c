/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_puthexalow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:29:22 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/04 18:11:28 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pf_puthexalow(unsigned long long int p)
{
	int				count;
	char			*hexa;

	hexa = "0123456789abcdef";
	count = 0;
	if (p >= 16)
		count += ft_pf_puthexalow(p / 16);
	count += ft_pf_putchar(hexa[p % 16]);
	return (count);
}
