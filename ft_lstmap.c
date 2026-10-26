/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:07:55 by abenabda          #+#    #+#             */
/*   Updated: 2026/10/19 19:53:59 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*c_node;
	void	*t_content;

	if (!lst || !f)
		return (NULL);
	t_content = f(lst->content);
	n_lst = ft_lstnew(t_content);
	if (!n_lst)
		return (NULL);
	c_node = n_lst;
	lst = lst->next;
	while (lst)
	{
		t_content = f(lst->content);
		c_node->next = ft_lstnew(t_content);
		if (!c_node->next)
		{
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		c_node = c_node->next;
		lst = lst->next;
	}
	return (n_lst);
}
