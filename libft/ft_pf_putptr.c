/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:28:34 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/04 18:11:28 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pf_putptr(void *p)
{
	unsigned long long	star;
	int					count;

	star = (unsigned long long)p;
	if (!p)
	{
		ft_pf_putstr("(nil)");
		return (5);
	}
	count = 0;
	count += ft_pf_putstr("0x");
	count += ft_pf_puthexalow(star);
	return (count);
}
