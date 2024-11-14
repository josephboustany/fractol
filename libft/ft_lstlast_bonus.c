/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:49:02 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/22 17:57:34 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*pt_t_list;

	pt_t_list = lst;
	if (lst == 0)
		return (0);
	while (pt_t_list ->next != 0)
		pt_t_list = pt_t_list->next;
	return (pt_t_list);
}
