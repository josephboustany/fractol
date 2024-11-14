/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:25:45 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/13 21:10:43 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*endp;

	endp = (char *)s + ft_strlen(s);
	while (*endp != (unsigned char)c)
	{
		if (endp == s)
			return (NULL);
		endp--;
	}
	return (endp);
}
