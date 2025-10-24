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

int	is_number_valid(char *str)
{
	int	i;
	int	has_digit;
	int	has_dot;

	has_digit = 0;
	has_dot = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			has_digit = 1;
		else if (str[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else
			return (0);
		i++;
	}
	return (has_digit);
}

static double	ft_atof_ii(char *str, double res)
{
	int		i;
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
			return (1);
		deci /= 10;
		i++;
	}
	if (flag == 1 && str[i] == '.')
		return (1);
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
			return (1);
		i++;
	}
	res = ft_atof_ii(&str[i], res);
	return (res * symbol);
}
