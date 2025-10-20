/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:57:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/14 21:57:27 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	print_usage(int n)
{
	if (n == 1)
	{
		ft_putstr_fd("Usage:\n", 2);
		ft_putstr_fd("  ./fractol mandelbrot\n", 2);
		ft_putstr_fd("  ./fractol julia <real> <img>\n", 2);
		exit(1);
	}
	if (n == 2)
	{
		ft_putstr_fd("Usage:\n", 2);
		ft_putstr_fd("  ./fractol mandelbrot\n", 2);
		ft_putstr_fd("  ./fractol julia\n", 2);
		exit(1);
	}
	if (n == 3)
	{
		ft_putstr_fd("Usage:\n", 2);
		ft_putstr_fd("  ./fractol mandelbrot\n", 2);
		ft_putstr_fd("  ./fractol julia <real> <img>\n", 2);
		exit(1);
	}
}

char	*ft_strlower(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_strdup(str);
	while (str[i])
	{
		res[i] = ft_tolower(str[i]);
		i++;
	}
	return (res);
}
