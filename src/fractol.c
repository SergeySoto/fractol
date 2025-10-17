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
	fractol->julia_c.re = JULIA_C_REAL;
	fractol->julia_c.im = JULIA_C_IMAG;
	return (set_type(argc, argv, fractol));
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;
	
	init_fractol(argc, argv, &fractol);
	// printf("Type: %d\n", fractol.type);
	// printf("Julia C: %.5f + %.5fi\n", fractol.julia_c.re, fractol.julia_c.im);
	// printf("Zoom: %.2f\n", fractol.zoom);
	// printf("Limits: [%.2f, %.2f] x [%.2f, %.2f]\n", 
	// 	fractol.re_min, fractol.re_max, fractol.im_min, fractol.im_max);

	fractol.mlx = mlx_init(800, 600, "Fractol", true);
	if (!fractol.mlx)
	{
		ft_putstr_fd("❌ Failed to initialize MLX42\n", 2);
		return (1);
	}
	fractol.img = mlx_new_image(fractol.mlx, fractol.width, fractol.height);
	if (!fractol.img)
	{
		mlx_terminate(fractol.mlx);
		return (ft_putstr_fd("❌ Failed to create image\n", 2), 0);
	}
	if (mlx_image_to_window(fractol.mlx, fractol.img, 0, 0) < 0)
	{
		mlx_terminate(fractol.mlx);
		return (ft_putstr_fd("❌ Failed to display image\n", 2), 0);
	}
	ft_putstr_fd("✅ Window created successfully!\n", 1);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);

	return (0);
}
