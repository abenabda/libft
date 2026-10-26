/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:56:20 by abenabda          #+#    #+#             */
/*   Updated: 2026/10/14 18:36:52 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	init_dest;
	size_t	init_src;
	size_t	i;

	init_src = ft_strlen(src);
	init_dest = 0;
	while (init_dest < size && dest[init_dest])
		init_dest++;
	i = 0;
	if (init_dest < size)
	{
		while (i < size - init_dest - 1 && src[i])
		{
			dest[init_dest + i] = src[i];
			i++;
		}
		dest[init_dest + i] = '\0';
	}
	return (init_dest + init_src);
}
