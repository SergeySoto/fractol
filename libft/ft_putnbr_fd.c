/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:59:39 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/05/13 21:45:01 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;
	long int	d;
	int			r;

	num = n;
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	d = 1;
	while (num / d >= 10)
		d *= 10;
	while (d > 0)
	{
		r = num / d;
		ft_putchar_fd(r + '0', fd);
		num %= d;
		d /= 10;
	}
}
