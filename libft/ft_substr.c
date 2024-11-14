/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:50:09 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/15 19:51:40 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substring_len;
	size_t	s_len;
	char	*substring;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		substring_len = s_len - start;
	else
		substring_len = len;
	substring = (char *)malloc(sizeof(char) * (substring_len + 1));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, s + start, substring_len + 1);
	substring[substring_len] = '\0';
	return (substring);
}
