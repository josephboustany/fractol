/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:09:29 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/13 18:58:27 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	j;

	len_dst = ft_strlen ((const char *)dst);
	len_src = ft_strlen (src);
	if (size <= len_dst)
	{
		return (size + len_src);
	}
	i = len_dst;
	j = 0;
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}
