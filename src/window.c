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
	fractol->mlx = mlx_init(fractol->width, fractol->height, "Fractol", true);
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

static uint32_t	get_color(int iter, t_fractol *fractol)
{
	double	ratio;
	int		r;
	int		g;
	int		b;

	ratio = 0.0;
	if (iter == fractol->max_iter)
		return (BLACK);
	ratio = sqrt((double)iter / fractol->max_iter);
	r = (uint8_t)(sin((ratio + fractol->color_shift) * M_PI * 2.0) * 127.5 + 127.5);
	g = (uint8_t)(sin((ratio + fractol->color_shift) * M_PI * 2.0 + 2.0) * 127.5 + 127.5);
	b = (uint8_t)(sin((ratio + fractol->color_shift) * M_PI * 2.0 + 4.0) * 127.5 + 127.5);
	fractol->color_draw = (r << 24) | (g << 16) | (b << 8) | 0xFF;
	return (fractol->color_draw);
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
			else
				iter = 0;
			mlx_put_pixel(fractol->img, x, y, get_color(iter, fractol));
			y++;
		}
		x++;
	}
}
