/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:02:24 by abenabda          #+#    #+#             */
/*   Updated: 2026/10/19 20:14:59 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	ft_word_count(char const *s, char c)
{
	int	count;
	int	len;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = ft_word_len(s, c);
			count++;
			s += len;
		}
	}
	return (count);
}

static char	*ft_copy_words(char const *s, int len)
{
	char	*new_s;
	int		i;

	new_s = malloc(len + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

static char	**ft_free_result(char **result, int i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_word_count(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		len = ft_word_len(s, c);
		result[i] = ft_copy_words(s, len);
		if (!result[i])
			return (ft_free_result(result, i));
		s += len;
		i++;
	}
	result[i] = NULL;
	return (result);
}
