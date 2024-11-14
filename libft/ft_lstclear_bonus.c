/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:41:46 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/22 17:52:46 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		current = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = current;
	}
}
