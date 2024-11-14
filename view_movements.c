/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:59:03 by jboustan          #+#    #+#             */
/*   Updated: 2024/09/05 20:14:20 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pan_fractal_view(t_fractal *fractal, int current_mouse_x,
	int current_mouse_y)
{
	double	view_width;
	double	view_height;
	double	horizontal_shift;
	double	vertical_shift;

	view_width = fractal->x_max_bound - fractal->x_min_bound;
	view_height = fractal->y_max_bound - fractal->y_min_bound;
	horizontal_shift = (current_mouse_x - fractal->last_x_pos)
		* view_width / WIDTH;
	vertical_shift = (current_mouse_y - fractal->last_y_pos)
		* view_height / HEIGHT;
	fractal->x_min_bound -= horizontal_shift;
	fractal->x_max_bound -= horizontal_shift;
	fractal->y_min_bound -= vertical_shift;
	fractal->y_max_bound -= vertical_shift;
	fractal->last_x_pos = current_mouse_x;
	fractal->last_y_pos = current_mouse_y;
}

void	refresh_fractal_display(t_fractal *fractal)
{
	if (ft_strncmp(&fractal->fractal_type, "m", 1) == 0)
		render_mandelbrot_set(&fractal->img_data, fractal, fractal->max_depth);
	else if (ft_strncmp(&fractal->fractal_type, "j", 1) == 0)
		render_julia_set(&fractal->img_data, fractal, fractal->max_depth);
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->img_data.image, 0, 0);
}

void	adjust_julia_position(t_fractal *fractal, double real_shift,
											double imag_shift)
{
	fractal->img_data.c.zx += real_shift;
	fractal->img_data.c.zy += imag_shift;
	render_julia_set(&fractal->img_data, fractal, fractal->max_depth);
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->img_data.image, 0, 0);
}
