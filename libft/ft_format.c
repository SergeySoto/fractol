/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:00:55 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/04 18:11:28 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(char ch, va_list ap)
{
	int	count;

	count = 0;
	if (ch == 'c')
		count += ft_pf_putchar(va_arg(ap, int));
	else if (ch == 's')
		count += ft_pf_putstr(va_arg(ap, char *));
	else if (ch == 'p')
		count += ft_pf_putptr(va_arg(ap, void *));
	else if (ch == 'd')
		count += ft_pf_putint(va_arg(ap, int));
	else if (ch == 'i')
		count += ft_pf_putint(va_arg(ap, int));
	else if (ch == 'u')
		count += ft_pf_putuint(va_arg(ap, unsigned int));
	else if (ch == 'x')
		count += ft_pf_puthexalow(va_arg(ap, unsigned int));
	else if (ch == 'X')
		count += ft_pf_puthexaup(va_arg(ap, unsigned int));
	else
		count += ft_pf_putchar('%');
	return (count);
}
