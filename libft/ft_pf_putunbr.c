/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putunbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:25:18 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/04 18:11:28 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pf_putunbr(unsigned int n)
{
	long int	num;
	long int	d;
	int			r;
	int			count;

	num = n;
	count = 0;
	if (num == 0)
	{
		count += ft_pf_putchar('0');
		return (count);
	}
	d = 1;
	while (num / d >= 10)
		d *= 10;
	while (d > 0)
	{
		r = num / d;
		count += ft_pf_putchar(r + '0');
		num %= d;
		d /= 10;
	}
	return (count);
}
