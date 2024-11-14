/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:44:36 by jboustan          #+#    #+#             */
/*   Updated: 2024/09/05 18:46:27 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute_zoom(t_fractal *fractal, char *zoom_direction)
{
	double	x_center;
	double	y_center;
	double	x_distance;
	double	y_distance;

	x_center = (fractal->x_min_bound + fractal->x_max_bound) / 2.0;
	y_center = (fractal->y_min_bound + fractal->y_max_bound) / 2.0;
	x_distance = fractal->x_max_bound - fractal->x_min_bound;
	y_distance = fractal->y_max_bound - fractal->y_min_bound;
	if (ft_strncmp(zoom_direction, "in", 2) == 0)
	{
		x_distance *= 0.98;
		y_distance *= 0.98;
	}
	else if (ft_strncmp(zoom_direction, "out", 3) == 0)
	{
		x_distance *= 1.02;
		y_distance *= 1.02;
	}
	fractal->x_min_bound = x_center - x_distance / 2.0;
	fractal->x_max_bound = x_center + x_distance / 2.0;
	fractal->y_min_bound = y_center - y_distance / 2.0;
	fractal->y_max_bound = y_center + y_distance / 2.0;
}

void	apply_zoom(t_fractal *fractal, char *zoom_direction)
{
	compute_zoom(fractal, zoom_direction);
	if (ft_strncmp(&fractal->fractal_type, "m", 1) == 0)
		render_mandelbrot_set(&fractal->img_data, fractal, fractal->max_depth);
	else if (ft_strncmp(&fractal->fractal_type, "j", 1) == 0)
		render_julia_set(&fractal->img_data, fractal, fractal->max_depth);
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->img_data.image, 0, 0);
}

void	update_iteration_limit(t_fractal *fractal, int iteration_delta)
{
	fractal->max_depth += iteration_delta;
	if (ft_strncmp(&fractal->fractal_type, "j", 1) == 0)
		render_julia_set(&fractal->img_data, fractal, fractal->max_depth);
	else if (ft_strncmp(&fractal->fractal_type, "m", 1) == 0)
		render_mandelbrot_set(&fractal->img_data, fractal, fractal->max_depth);
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->img_data.image, 0, 0);
}
