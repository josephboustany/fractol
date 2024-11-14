/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:23:54 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/15 23:27:13 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;
	size_t	space;

	space = nmemb * size;
	if (size > 0 && nmemb > 2147483647 / size)
		return (NULL);
	pt = malloc(nmemb * size);
	if (!pt)
		return (NULL);
	ft_memset(pt, 0, space);
	return (pt);
}
