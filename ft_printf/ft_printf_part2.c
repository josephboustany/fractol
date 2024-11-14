/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:00:21 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/29 23:01:46 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunumbr(unsigned int number)
{
	int	count;

	count = 0;
	if (number > 9)
		count += ft_putunumbr(number / 10);
	write(1, &"0123456789"[number % 10], 1);
	return (count + 1);
}

int	ft_puthexadecimal(unsigned int number, char *base)
{
	int	count;

	count = 0;
	if (number >= 16)
		count += ft_puthexadecimal(number / 16, base);
	write(1, &base[number % 16], 1);
	return (count + 1);
}

int	ft_putaddress(void *ptr)
{
	unsigned long	address;
	char			*hex_array;
	char			reverse_array[16];
	int				i;
	int				j;

	if (!ptr)
		return (ft_putstr("(nil)"), 5);
	address = (unsigned long)ptr;
	hex_array = "0123456789abcdef";
	j = 0;
	while (address || j == 0)
	{
		reverse_array[j++] = hex_array[address % 16];
		address /= 16;
	}
	i = ft_putstr("0x");
	while (j)
		i += ft_putchar(reverse_array[--j]);
	return (i);
}
