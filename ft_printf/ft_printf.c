/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:07:12 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/29 22:49:04 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += process_format_specifier(str[i + 1], args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	process_format_specifier(char next, va_list args)
{
	int	count;

	count = 0;
	if (next == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (next == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (next == '%')
		count = ft_putchar('%');
	else if (next == 'd' || next == 'i')
		count = ft_putnumbr(va_arg(args, int));
	else if (next == 'X')
		count = ft_puthexadecimal(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (next == 'x')
		count = ft_puthexadecimal(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (next == 'p')
		count = ft_putaddress(va_arg(args, void *));
	else if (next == 'u')
		count = ft_putunumbr(va_arg(args, unsigned int));
	else
		count = -1;
	return (count);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putnumbr(int number)
{
	int	count;

	count = 0;
	if (number == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		number = 147483648;
	}
	if (number < 0)
	{
		count += ft_putchar('-');
		number = -number;
	}
	if (number >= 10)
		count += ft_putnumbr(number / 10);
	count += ft_putchar(number % 10 + '0');
	return (count);
}
