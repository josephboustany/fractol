/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:58:32 by jboustan          #+#    #+#             */
/*   Updated: 2024/09/04 22:59:13 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <unistd.h>
# include <X11/Xlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define WIDTH 1000
# define HEIGHT 1000
# define FRACTAL_MAX 1250

typedef struct s_complex_number {
	double	zx;
	double	zy;
}	t_complex_number;

typedef struct s_fractal_data {
	void				*image;
	char				*img_data;
	int					bpp;
	int					row_size;
	int					endian;
	int					zoom_x;
	int					zoom_y;
	t_complex_number	c;
}	t_fractal_data;

typedef struct t_fractal {
	t_fractal_data	img_data;
	void			*mlx;
	void			*window;
	double			x_min_bound;
	double			x_max_bound;
	double			y_min_bound;
	double			y_max_bound;
	double			zoom_factor;
	int				mouse_pressed;
	int				mouse_moved;
	int				last_x_pos;
	int				last_y_pos;
	char			fractal_type;
	int				max_depth;
}	t_fractal;

typedef struct iteration_indices
{
	int	index_x;
	int	index_y;
}	t_iteration_indices;

typedef struct s_scale_factors {
	double	scale_x;
	double	scale_y;
}	t_scale_factors;

typedef struct s_squared_values {
	double	re_sq;
	double	im_sq;
}	t_squared_values;

double	extract_integer_part(const char *str, int *index,
			int *is_negative_flag);
double	extract_fractional_part(const char *str, int start_index);
double	convert_string_to_double(const char *number_str);
int		is_in_mandelbrot_set(t_complex_number c, int iteration_limit);
int		is_in_julia_set(t_complex_number z, t_complex_number c,
			int iteration_limit);
int		calculate_color(int current_iteration, int max_iterations);
int		handle_key_event(int keycode, t_fractal *fractal);
int		handle_mouse_click(int button, int x, int y, t_fractal *fractal);
int		handle_mouse_release(int button, int mouse_x,
			int mouse_y, t_fractal *fractal);
int		handle_mouse_drag(int mouse_x, int mouse_y, t_fractal *fractal);
int		validate_number_string(const char *number_str);
int		cleanup_and_exit(t_fractal *fractal);
void	place_pixel(t_fractal_data *image_data, int x, int y, int color);
void	render_mandelbrot_set(t_fractal_data *img, t_fractal *frac,
			int iteration_limit);
void	initialize_event_hooks(t_fractal *fractal);
void	render_julia_set(t_fractal_data *img, t_fractal *frac,
			int iteration_limit);
void	compute_zoom(t_fractal *fractal, char *zoom_direction);
void	apply_zoom(t_fractal *fractal, char *zoom_direction);
void	adjust_julia_position(t_fractal *fractal, double real_shift,
			double imag_shift);
void	update_iteration_limit(t_fractal *fractal, int iteration_delta);
void	pan_fractal_view(t_fractal *fractal, int current_mouse_x,
			int current_mouse_y);
void	refresh_fractal_display(t_fractal *fractal);
void	display_usage_instructions(void);
void	setup_fractal_environment(t_fractal *fractal, int width,
			int height, char fractal_type);
void	initialize_and_render_mandelbrot(t_fractal *fractal);
void	initialize_and_render_julia(t_fractal *fractal,
			char *real_part_str, char *imaginary_part_str);

#endif
