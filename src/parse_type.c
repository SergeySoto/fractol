/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:50:38 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/16 18:50:38 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	free_trimmed(char* str1, char* str2, char* str3)
{
	free(str1);
	free(str2);
	free(str3);
}

static void	set_julia(char *trimmed_re, char *trimmed_im, t_fractol *fractol)
{
	fractol->type = JULIA;
	fractol->julia_c.re = ft_atof(trimmed_re);
	fractol->julia_c.im = ft_atof(trimmed_im);
	fractol->im_min = -2.0;
	fractol->im_max = 2.0;
}

int	set_type(int argc, char **argv, t_fractol *fractol)
{
	char	*fractol_type;

	if (argc < 2 || argc > 4)
		return (print_usage(1));
	fractol_type = ft_strlower(argv[1]);
	if (argc == 2)
		return (validate_mandejul(fractol_type, fractol));
	if (argc == 3)
	{
		free(fractol_type);
		return (print_usage(3));
	}
	if (argc == 4)
		return (validate_julia(argv, fractol_type, fractol));
	else
	{
		free(fractol_type);
		return (print_usage(3));
	}
}

int	validate_mandejul(char *fractol_type, t_fractol *fractol)
{
	if (ft_strcmp(fractol_type, "mandelbrot") == 0)
	{
		fractol->type = MANDELBROT;
		free(fractol_type);
		return (0);
	}
	else if (ft_strcmp(fractol_type, "julia") == 0)
	{
		fractol->type = JULIA;
		fractol->im_min = -2.0;
		fractol->im_max = 2.0;
		free(fractol_type);
		return (0);
	}
	else
	{
		free(fractol_type);
		return (print_usage(2));
	}
}

int	validate_julia(char **argv, char *fractol_type, t_fractol *fractol)
{
	char	*trimmed_re;
	char	*trimmed_im;

	if (ft_strcmp(fractol_type, "julia") != 0)
	{
		free(fractol_type);
		return (print_usage(3));
	}
	trimmed_re = ft_strtrim(argv[2], " ");
	trimmed_im = ft_strtrim(argv[3], " ");
	if (!trimmed_re || !trimmed_im)
	{
		free_trimmed(trimmed_re, trimmed_im, fractol_type);
		return (1);
	}
	if (!is_number_valid(trimmed_re) || !is_number_valid(trimmed_im))
	{
		free_trimmed(trimmed_re, trimmed_im, fractol_type);
		return (ft_putstr_fd("Error: Invalid number format\n", 2), 1);
	}
	set_julia(trimmed_re, trimmed_im, fractol);
	free_trimmed(trimmed_re, trimmed_im, fractol_type);
	return (0);
}
