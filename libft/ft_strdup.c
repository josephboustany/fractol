/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:59:29 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/15 16:39:21 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*result;

	s_len = ft_strlen(s);
	result = (char *)ft_memcpy(malloc(sizeof(char) * s_len + 1),
			(const void *)s, s_len);
	if (!result)
		return (NULL);
	result[s_len] = '\0';
	return ((char *)result);
}
