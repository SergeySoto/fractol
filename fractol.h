/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:11:15 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/10/08 18:11:15 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <sys/wait.h>
# include <stdint.h>
# include <stdbool.h>
# include <math.h>
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITER 100
# define ESCAPE_RADIUS 4.0
# define X_MIN -2.0
# define X_MAX 2.0
# define Y_MIN -1.5
# define Y_MAX 1.5
# define ZOOM_FACTOR 1.1
# define MOVE_FACTOR 0.1
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define COLOR_SHIFT 15
# define JULIA_C_REAL -0.7
# define JULIA_C_IMAG 0.27015

typedef struct s_calc
{
	double	re;
	double	im;
}			t_calc;

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
}	t_fractal_type;

typedef struct s_fractol
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_fractal_type	type;
	t_calc			julia_c;
	int				width;
	int				height;
	double			zoom;
	double			re_min;
	double			re_max;
	double			im_min;
	double			im_max;
	uint32_t		color_draw;
	int				max_iter;
	double			escape_value;
	double			offset_x;
	double			offset_y;
}					t_fractol;

int		init_fractol(int argc, char **argv, t_fractol *fractol);
//Fractol utils
int		print_usage(int n);
char	*ft_strlower(char *str);
//ft_atof
int		is_number_valid(char *str);
double	ft_atof(char *str);
//Parse type
int		set_type(int argc, char **argv, t_fractol *fractol);
int		validate_mandejul(char *fractol_type, t_fractol *fractol);
int		validate_julia(char **argv, char *fractol_type, t_fractol *fractol);

#endif