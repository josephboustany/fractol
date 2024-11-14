/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:03:25 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/22 17:31:29 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(int number)
{
	size_t	i;

	i = 0;
	if (number <= 0)
		i++;
	while (number != 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int number)
{
	char	*stringnumber;
	long	longnumber;
	size_t	length;

	longnumber = (long)number;
	length = ft_num_len(longnumber);
	stringnumber = (char *)malloc((sizeof(char) * (length + 1)));
	if (!stringnumber)
		return (NULL);
	stringnumber[length--] = '\0';
	if (longnumber == 0)
		stringnumber[0] = '0';
	if (longnumber < 0)
	{
		stringnumber[0] = '-';
		longnumber = (-1) * longnumber;
	}
	while (longnumber > 0)
	{
		stringnumber[length] = (longnumber % 10) + '0';
		longnumber = longnumber / 10;
		length--;
	}
	return (stringnumber);
}
