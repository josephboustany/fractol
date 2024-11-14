/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:24:51 by jboustan          #+#    #+#             */
/*   Updated: 2024/09/04 21:27:12 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	place_pixel(t_fractal_data *image_data, int x, int y, int color)
{
	char	*pixel_address;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel_address = image_data->img_data
			+ (y * image_data->row_size + x * (image_data->bpp / 8));
		ft_memcpy(pixel_address, &color, sizeof(int));
	}
}

int	calculate_color(int current_iteration, int max_iterations)
{
	double	normalized_log_scale;
	int		red_component;
	int		green_component;
	int		blue_component;
	int		final_color;

	normalized_log_scale = log((double)current_iteration + 1e-10)
		/ log((double)max_iterations + 1e-10);
	red_component = (int)(9 * (1 - normalized_log_scale) * normalized_log_scale
			* normalized_log_scale * normalized_log_scale * 255);
	green_component = (int)(15 * (1 - normalized_log_scale)
			* (1 - normalized_log_scale) * normalized_log_scale
			* normalized_log_scale * 255);
	blue_component = (int)(8.5 * (1 - normalized_log_scale)
			* (1 - normalized_log_scale)
			* (1 - normalized_log_scale) * normalized_log_scale * 255);
	final_color = (red_component << 16) | (green_component << 8)
		| blue_component;
	return (final_color);
}
