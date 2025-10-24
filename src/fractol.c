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
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->re_min = X_MIN;
	fractol->re_max = X_MAX;
	fractol->im_min = Y_MIN;
	fractol->im_max = Y_MAX;
	fractol->color_draw = WHITE;
	fractol->max_iter = MAX_ITER;
	fractol->escape_value = ESCAPE_RADIUS;
	fractol->complex.re = 0.0;
	fractol->complex.im = 0.0;
	fractol->julia_c.re = JULIA_C_REAL;
	fractol->julia_c.im = JULIA_C_IMAG;
	return (set_type(argc, argv, fractol), 0);
}

static uint32_t	get_color(int iter, t_fractol *fractol)
{
	double	ratio;
	int	R;
	int	G;
	int	B;
	int	A;

	A = 255;
	ratio = 0.0;
	if (iter == fractol->max_iter)
		fractol->color_draw = BLACK;
	else
		ratio = (double)iter / fractol->max_iter;
	R = 255 + ratio * (0 - 255);
	G = 255 + ratio * (0 - 255);
	B = 255 + ratio * (0 - 255);
	fractol->color_draw = (R << 24) | (G << 16) | (B << 8) | A;
	return (fractol->color_draw);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	init_fractol(argc, argv, &fractol);
	if (init_window(&fractol) != 0)
		return (1);
	render_fractol(&fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	// printf("Type: %d\n", fractol.type);
	// printf("Julia C: %.5f + %.5fi\n", fractol.complex.re, fractol.complex.im);
	// printf("Zoom: %.2f\n", fractol.zoom);
	// printf("Limits: [%.2f, %.2f] x [%.2f, %.2f]\n", 
	// 	fractol.re_min, fractol.re_max, fractol.im_min, fractol.im_max);
	return (0);
}
