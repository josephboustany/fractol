/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:37:13 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/12 21:36:13 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (size > 1 && *src != '\0')
	{
		*dst++ = *src++;
		size--;
	}
	if (size > 0)
		*dst = '\0';
	return (src_len);
}
