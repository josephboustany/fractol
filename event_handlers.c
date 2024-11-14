/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:53:20 by jboustan          #+#    #+#             */
/*   Updated: 2024/09/05 18:58:32 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_event(int keycode, t_fractal *f)
{
	if (keycode == 65307)
		cleanup_and_exit(f);
	if (keycode == 65361)
		pan_fractal_view(f, f->last_x_pos - 10, f->last_y_pos);
	if (keycode == 65363)
		pan_fractal_view(f, f->last_x_pos + 10, f->last_y_pos);
	if (keycode == 65362)
		pan_fractal_view(f, f->last_x_pos, f->last_y_pos - 10);
	if (keycode == 65364)
		pan_fractal_view(f, f->last_x_pos, f->last_y_pos + 10);
	if (keycode == 65365)
		update_iteration_limit(f, 1);
	if (keycode == 65366)
		update_iteration_limit(f, -1);
	if (keycode == 65360 && ft_strncmp(&f->fractal_type, "j", 1) == 0)
		adjust_julia_position(f, -0.003, -0.003);
	if (keycode == 65367 && ft_strncmp(&f->fractal_type, "j", 1) == 0)
		adjust_julia_position(f, 0.003, 0.003);
	if (keycode == 65451)
		apply_zoom(f, "in");
	if (keycode == 65453)
		apply_zoom(f, "out");
	refresh_fractal_display(f);
	return (0);
}

int	handle_mouse_click(int button, int x, int y, t_fractal *fractal)
{
	if (button == 1)
	{
		fractal->mouse_pressed = 1;
		fractal->last_x_pos = x;
		fractal->last_y_pos = y;
	}
	else if (button == 4)
		apply_zoom(fractal, "in");
	else if (button == 5)
		apply_zoom(fractal, "out");
	return (0);
}

int	handle_mouse_release(int button, int mouse_x, int mouse_y,
	t_fractal *fractal)
{
	(void)mouse_x;
	(void)mouse_y;
	(void)fractal;
	if (button == 1)
		fractal->mouse_pressed = 0;
	return (0);
}

int	handle_mouse_drag(int mouse_x, int mouse_y, t_fractal *fractal)
{
	static int	redraw_counter = 0;

	if (!fractal->mouse_pressed)
		return (0);
	if (redraw_counter >= 3)
	{
		pan_fractal_view(fractal, mouse_x, mouse_y);
		refresh_fractal_display(fractal);
		redraw_counter = 0;
	}
	redraw_counter++;
	return (0);
}
