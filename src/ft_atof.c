/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:03:47 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/16 20:03:47 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	ft_atof_II(char *str, double res)
{
	int	i;
	double	deci;
	int		flag;

	i = 0;
	deci = 0.1;
	flag = 0;
	if (str[i] == '.')
	{
		i++;
		flag = 1;
	}
	while (str[i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]) == 1)
			res = res + ((str[i] - '0') * deci);
		else
			return (ft_putstr_fd("Error: Invalid number format\n", 2), 0.0);
		deci /= 10;
		i++;
	}
	if (flag == 1 && str[i] == '.')
		return (ft_putstr_fd("Error: Invalid number format\n", 2), 0.0);
	return (res);
}

double	ft_atof(char *str)
{
	int		i;
	int		symbol;
	double	res;

	i = 0;
	symbol = 1;
	res = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			symbol *= -1;
		i++;
	}
	while (str[i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]) == 1)
			res = res * 10 + (str[i] - '0');
		else
			return (ft_putstr_fd("Error: Invalid number format\n", 2), 0.0);
		i++;
	}
	res = ft_atof_II(&str[i], res);
	return (res * symbol);
}
