/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:05:51 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/26 10:05:51 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	handler_escape(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fractol->mlx);
}

void	handler_scroll(double xdelta, double ydelta, void *param)
{
	(void)xdelta;
	t_fractol	*fractol;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		mouse_ratio_x;
    double		mouse_ratio_y;
	double		mouse_re;
	double		mouse_im;
	double		re_range;
	double		im_range;
	double		zoom_factor;
	
	fractol = (t_fractol *)param;
	if (ydelta > 0)
		zoom_factor = 0.9;
	else if (ydelta < 0)
		zoom_factor = 1.1;
	mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);
	mouse_re = fractol->re_min + ((double)mouse_x / (double)fractol->width) * (fractol->re_max - fractol->re_min);
	mouse_im = fractol->im_min + ((double)mouse_y / (double)fractol->height) * (fractol->im_max - fractol->im_min);
	re_range = (fractol->re_max - fractol->re_min) * zoom_factor;
	im_range = (fractol->im_max - fractol->im_min) * zoom_factor;
	mouse_ratio_x = (double)mouse_x / (double)fractol->width;
	mouse_ratio_y = (double)mouse_y / (double)fractol->height;
	fractol->re_min = mouse_re - re_range * mouse_ratio_x;
	fractol->re_max = mouse_re + re_range * (1.0 - mouse_ratio_x);
	fractol->im_min = mouse_im - im_range * mouse_ratio_y;
	fractol->im_max = mouse_im + im_range * (1.0 - mouse_ratio_y);
	render_fractol(fractol);
}
