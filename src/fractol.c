/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:20:48 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/08 18:20:48 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	init_fractol(int argc, char **argv, t_fractol *fractol)
{
	fractol->mlx = NULL;
	fractol->img = NULL;
	fractol->width = WIDTH;
	fractol->height = HEIGHT;
	fractol->zoom = 1.0;
	fractol->re_min = X_MIN;
	fractol->re_max = X_MAX;
	fractol->im_min = Y_MIN;
	fractol->im_max = Y_MAX;
	fractol->color_draw = WHITE;
	fractol->max_iter = MAX_ITER;
	fractol->escape_value = ESCAPE_RADIUS;
	fractol->complex.re = 0.0;
	fractol->complex.im = 0.0;
	fractol->color_shift = 0.0;
	fractol->julia_c.re = JULIA_C_REAL;
	fractol->julia_c.im = JULIA_C_IMAG;
	return (set_type(argc, argv, fractol), 0);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	init_fractol(argc, argv, &fractol);
	if (init_window(&fractol) != 0)
		return (1);
	render_fractol(&fractol);
	mlx_key_hook(fractol.mlx, handler_key, &fractol);
	mlx_scroll_hook(fractol.mlx, handler_scroll, &fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (0);
}
