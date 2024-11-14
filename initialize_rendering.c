/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_rendering.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:02:52 by jboustan          #+#    #+#             */
/*   Updated: 2024/09/05 20:13:42 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_fractal_environment(t_fractal *fractal, int width,
		int height, char fractal_type)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		exit(1);
	fractal->window = mlx_new_window(fractal->mlx, width,
			height, "FRACTAL SET");
	if (fractal->window == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		exit(1);
	}
	fractal->img_data.image = mlx_new_image(fractal->mlx, width, height);
	fractal->img_data.img_data = mlx_get_data_addr(fractal->img_data.image,
			&fractal->img_data.bpp, &fractal->img_data.row_size,
			&fractal->img_data.endian);
	fractal->x_min_bound = -2;
	fractal->x_max_bound = 1;
	fractal->y_min_bound = -1.5;
	fractal->y_max_bound = 1.5;
	fractal->zoom_factor = 1.0;
	fractal->max_depth = 50;
	fractal->fractal_type = fractal_type;
	fractal->last_x_pos = 0;
	fractal->last_y_pos = 0;
	fractal->mouse_pressed = 0;
}

int	cleanup_and_exit(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img_data.image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}

void	initialize_and_render_mandelbrot(t_fractal *fractal)
{
	setup_fractal_environment(fractal, WIDTH, HEIGHT, 'm');
	render_mandelbrot_set(&fractal->img_data, fractal, fractal->max_depth);
	initialize_event_hooks(fractal);
}

void	initialize_and_render_julia(t_fractal *fractal,
	char *real_part_str, char *imaginary_part_str)
{
	if (!validate_number_string(real_part_str)
		|| !validate_number_string(imaginary_part_str))
	{
		ft_printf("Input error: Invalid number format\n");
		return ;
	}
	fractal->img_data.c.zy = convert_string_to_double(imaginary_part_str);
	fractal->img_data.c.zx = convert_string_to_double(real_part_str);
	if (abs((int)fractal->img_data.c.zy) >= 3
		|| abs((int)fractal->img_data.c.zx) >= 3)
	{
		ft_printf("Error: The real or imaginary part of 'c' is too large.\n");
		ft_printf("It is preferable to have both real ");
		ft_printf("and imaginary parts less than 3.\n");
		return ;
	}
	setup_fractal_environment(fractal, WIDTH, HEIGHT, 'j');
	fractal->x_min_bound = -2.0;
	fractal->x_max_bound = 2.0;
	fractal->y_min_bound = -2.0;
	fractal->y_max_bound = 2.0;
	render_julia_set(&fractal->img_data, fractal, fractal->max_depth);
	initialize_event_hooks(fractal);
}

void	initialize_event_hooks(t_fractal *fractal)
{
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->img_data.image, 0, 0);
	mlx_hook(fractal->window, 17, 1L << 0,
		(int (*)(void *))cleanup_and_exit, fractal);
	mlx_key_hook(fractal->window,
		(int (*)(int, void *))handle_key_event, fractal);
	mlx_mouse_hook(fractal->window, handle_mouse_click, fractal);
	mlx_hook(fractal->window, 6, PointerMotionMask, handle_mouse_drag, fractal);
	mlx_hook(fractal->window, 5, 1L << 3, handle_mouse_release, fractal);
	mlx_loop(fractal->mlx);
}
