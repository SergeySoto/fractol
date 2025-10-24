/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:34:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/22 16:34:27 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	init_window(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!fractol->mlx)
		return (ft_putstr_fd("❌ Failed to initialize MLX42\n", 2), 1);
	fractol->img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	if (!fractol->img)
	{
		mlx_terminate(fractol->mlx);
		return (ft_putstr_fd("❌ Failed to create image\n", 2), 1);
	}
	if (mlx_image_to_window(fractol->mlx, fractol->img, 0, 0) < 0)
	{
		mlx_terminate(fractol->mlx);
		return (ft_putstr_fd("❌ Failed to display image\n", 2), 1);
	}
	ft_putstr_fd("✅ Window created successfully!\n", 1);
	return (0);
}

void	map_pixel_to_complex(int x, int y, t_fractol *fractol)
{
	fractol->complex.re = fractol->re_min
		+ ((double)x / fractol->width) * (fractol->re_max - fractol->re_min);
	fractol->complex.im = fractol->im_min
		+ ((double)y / fractol->height) * (fractol->im_max - fractol->im_min);
}

void	render_fractol(t_fractol *fractol)
{
	int	x;
	int	y;
	int	iter;

	x = 0;
	while (x < fractol->width)
	{
		y = 0;
		while (y < fractol->height)
		{
			map_pixel_to_complex(x, y, fractol);
			if (fractol->type == MANDELBROT)
				iter = mandelbrot(fractol);
			else if (fractol->type == JULIA)
				iter = julia(fractol);
			if (iter == fractol->max_iter)
				fractol->color_draw = BLACK;
			else
				fractol->color_draw = WHITE;
			mlx_put_pixel(fractol->img, x, y, fractol->color_draw);
			y++;
		}
		x++;
	}
}
