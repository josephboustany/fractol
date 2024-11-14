/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:13:23 by jboustan          #+#    #+#             */
/*   Updated: 2024/09/05 20:13:31 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 1)
	{
		display_usage_instructions();
		return (0);
	}
	if (argc == 2 && ft_strncmp(argv[1], "m", ft_strlen(argv[1])) == 0
		&& ft_strlen(argv[1]) == 1)
		initialize_and_render_mandelbrot(&fractal);
	else if (argc == 4 && argv[1][0] == 'j' && ft_strlen(argv[1]) == 1)
		initialize_and_render_julia(&fractal, argv[2], argv[3]);
	else
	{
		ft_printf("Input error: Invalid arguments\n");
		return (0);
	}
	return (0);
}
