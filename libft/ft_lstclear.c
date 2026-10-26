/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:42:05 by abenabda          #+#    #+#             */
/*   Updated: 2026/10/19 18:04:11 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new_node;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		new_node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = new_node;
	}
}
