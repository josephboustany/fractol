/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:42:56 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/15 13:12:48 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = 0;
	while (little[little_len] != '\0')
		little_len++;
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (i + little_len > len)
			return (NULL);
		j = 0;
		while (big[i + j] == little[j] && j < little_len)
			j++;
		if (j == little_len)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
