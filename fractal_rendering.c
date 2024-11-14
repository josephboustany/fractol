/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:27:47 by jboustan          #+#    #+#             */
/*   Updated: 2024/09/05 18:41:39 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_in_mandelbrot_set(t_complex_number c, int iteration_limit)
{
	t_iteration_indices	iter_vars;
	double				distance;
	t_complex_number	z;
	t_squared_values	zsq;

	distance = sqrt((c.zx - 0.25) * (c.zx - 0.25) + c.zy * c.zy);
	if (c.zx <= distance - 2 * distance * distance + 0.25)
		return (iteration_limit);
	if ((c.zx + 1) * (c.zx + 1) + c.zy * c.zy <= 0.0625)
		return (iteration_limit);
	z.zx = 0;
	z.zy = 0;
	iter_vars.index_x = -1;
	while (++iter_vars.index_x < iteration_limit)
	{
		zsq.re_sq = z.zx * z.zx;
		zsq.im_sq = z.zy * z.zy;
		if ((zsq.re_sq + zsq.im_sq) > 4.0)
			return (iter_vars.index_x);
		z.zy = 2 * z.zx * z.zy + c.zy;
		z.zx = (zsq.re_sq - zsq.im_sq) + c.zx;
		if (c.zy == 0 && z.zy != 0)
			break ;
	}
	return (iteration_limit);
}

void	render_mandelbrot_set(t_fractal_data *img, t_fractal *frac,
	int iteration_limit)
{
	t_iteration_indices	pix;
	t_scale_factors		scale;
	t_complex_number	c;
	int					iter;

	scale.scale_x = (frac->x_max_bound - frac->x_min_bound) / WIDTH;
	scale.scale_y = (frac->y_max_bound - frac->y_min_bound) / HEIGHT;
	pix.index_x = 0;
	while (pix.index_x < WIDTH)
	{
		pix.index_y = 0;
		while (pix.index_y < HEIGHT)
		{
			c.zx = frac->x_min_bound + pix.index_x * scale.scale_x;
			c.zy = frac->y_min_bound + pix.index_y * scale.scale_y;
			iter = is_in_mandelbrot_set(c, iteration_limit);
			if (iter < iteration_limit)
				place_pixel(img, pix.index_x, pix.index_y,
					(0x000764 - 0xF0E442) * iter / HEIGHT + 0xF0E442);
			else
				place_pixel(img, pix.index_x, pix.index_y, 0x000000);
			pix.index_y++;
		}
		pix.index_x++;
	}
}

int	is_in_julia_set(t_complex_number z, t_complex_number c, int iteration_limit)
{
	double	z_r_sq;
	double	z_im_sq;
	int		iter_count;

	iter_count = 0;
	while (iter_count < iteration_limit)
	{
		z_r_sq = z.zx * z.zx;
		z_im_sq = z.zy * z.zy;
		if (z_r_sq + z_im_sq > 4)
			return (iter_count);
		z.zy = 2 * z.zx * z.zy + c.zy;
		z.zx = z_r_sq - z_im_sq + c.zx;
		iter_count++;
	}
	return (iteration_limit);
}

void	render_julia_set(t_fractal_data *img,
	t_fractal *frac, int iteration_limit)
{
	t_iteration_indices	pix;
	t_scale_factors		scale;
	t_complex_number	z;
	int					iter;

	scale.scale_x = (frac->x_max_bound - frac->x_min_bound) / WIDTH;
	scale.scale_y = (frac->y_max_bound - frac->y_min_bound) / HEIGHT;
	pix.index_x = 0;
	while (pix.index_x < WIDTH)
	{
		pix.index_y = 0;
		while (pix.index_y < HEIGHT)
		{
			z.zx = frac->x_min_bound + pix.index_x * scale.scale_x;
			z.zy = frac->y_min_bound + pix.index_y * scale.scale_y;
			iter = is_in_julia_set(z, img->c, iteration_limit);
			if (iter < iteration_limit)
				place_pixel(img, pix.index_x, pix.index_y,
					calculate_color(iter, iteration_limit));
			else
				place_pixel(img, pix.index_x, pix.index_y, 0x000000);
			pix.index_y++;
		}
		pix.index_x++;
	}
}
