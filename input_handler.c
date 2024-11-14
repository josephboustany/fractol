/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:58:33 by jboustan          #+#    #+#             */
/*   Updated: 2024/09/05 20:10:02 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	extract_integer_part(const char *str, int *index, int *is_negative_flag)
{
	double	integer_part;

	integer_part = 0.0;
	if (str[*index] == '-')
	{
		*is_negative_flag = 1;
		(*index)++;
	}
	else if (str[*index] == '+')
		(*index)++;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		integer_part = integer_part * 10.0 + (str[*index] - '0');
		(*index)++;
	}
	return (integer_part);
}

double	extract_fractional_part(const char *str, int start_index)
{
	double	fractional_value;
	double	divisor;

	fractional_value = 0.0;
	divisor = 1.0;
	while (str[start_index] >= '0' && str[start_index] <= '9')
	{
		fractional_value = fractional_value * 10.0 + (str[start_index] - '0');
		divisor *= 10.0;
		start_index++;
	}
	return (fractional_value / divisor);
}

double	convert_string_to_double(const char *number_str)
{
	double	final_value;
	int		is_negative_flag;
	int		current_index;

	is_negative_flag = 0;
	current_index = 0;
	final_value = extract_integer_part(number_str,
			&current_index, &is_negative_flag);
	if (number_str[current_index] == '.')
	{
		current_index++;
		final_value += extract_fractional_part(number_str, current_index);
	}
	if (is_negative_flag)
		final_value = -final_value;
	return (final_value);
}

int	validate_number_string(const char *number_str)
{
	int	has_decimal_point;
	int	has_digit;

	has_decimal_point = 0;
	has_digit = 0;
	while (*number_str == ' ')
		number_str++;
	if (*number_str == '-' || *number_str == '+')
		number_str++;
	while (*number_str)
	{
		if (ft_isdigit(*number_str))
			has_digit = 1;
		else if (*number_str == '.')
		{
			if (has_decimal_point)
				return (0);
			has_decimal_point = 1;
		}
		else
			return (0);
		number_str++;
	}
	return (has_digit);
}

void	display_usage_instructions(void)
{
	ft_printf("\n____________________________How to Use");
	ft_printf("____________________________\n\n\n");
	ft_printf("--------------------./fractol m------------------------\n");
	ft_printf("              Displays the Mandelbrot set\n\n");
	ft_printf(".--------------------/fractol j a b--------------------\n");
	ft_printf("  Displays the Julia set, where 'a'=Real[z] and 'b'=Img[z] ");
	ft_printf("of the complex number 'c'\n");
	ft_printf(" ./fractol j -0.745429 0.05 - Displays ");
	ft_printf("the Julia set having 'c' = ");
	ft_printf("-0.745429 + 0.05i\n\n");
	ft_printf("--------------------Controls-----------------------------\n");
	ft_printf(" a- Click and drag with the mouse: ");
	ft_printf("Move the fractal image around\n");
	ft_printf(" b- Scroll with the mouse wheel: Zoom in or out\n");
	ft_printf(" c- Click + or -: Zoom in or out\n");
	ft_printf(" d- Up/Down arrow keys: Move the image up or down\n");
	ft_printf(" e- Left/Right arrow keys: Move the image left or right\n");
	ft_printf(" f- PgUp/PgDn keys: Increase/Decrease");
	ft_printf(" the number of iterations\n");
	ft_printf(" g- Home/End keys: Modify the complex number 'c'");
	ft_printf(" (applicable to Julia set only)\n\n");
}
