/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:32:58 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/23 20:32:58 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_fractol *fractol)
{
	t_calc	z;
	t_calc	z_temp;
	int		iter;
	double	z_squared;

	z.im = 0.0;
	z.re = 0.0;
	iter = 0;
	while (iter < fractol->max_iter)
	{
		z_squared = (z.re * z.re) + (z.im * z.im);
		if (z_squared > fractol->escape_value)
			return (iter);
		z_temp.re = (z.re * z.re) - (z.im * z.im);
		z_temp.im = 2.0 * z.re * z.im;
		z.re = z_temp.re + fractol->complex.re;
		z.im = z_temp.im + fractol->complex.im;
		iter++;
	}
	return (iter);
}

int	julia(t_fractol *fractol)
{
	t_calc	z;
	t_calc	c;
	t_calc	z_temp;
	int		iter;
	double	z_squared;

	z.re = fractol->complex.re;
	z.im = fractol->complex.im;
	c.re = fractol->julia_c.re;
	c.im = fractol->julia_c.im;
	iter = 0;
	while (iter < fractol->max_iter)
	{
		z_squared = (z.re * z.re) + (z.im * z.im);
		if (z_squared > fractol->escape_value)
			return (iter);
		z_temp.re = (z.re * z.re) - (z.im * z.im);
		z_temp.im = 2.0 * z.re * z.im;
		z.re = z_temp.re + c.re;
		z.im = z_temp.im + c.im;
		iter++;
	}
	return (iter);
}
