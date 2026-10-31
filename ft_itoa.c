/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:11:05 by abenabda          #+#    #+#             */
/*   Updated: 2026/10/16 14:12:05 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_number_size(int n)
{
	long	nbr;
	long	di;
	long	i;

	di = 1;
	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while ((di * 10) <= nbr)
		di = di * 10;
	while (di > 0)
	{
		i++;
		di = di / 10;
	}
	return (i);
}

static void	handle_negative(long *nb, char *number, long *di, long *x)
{
	if (*nb < 0)
	{
		number[*x] = '-';
		*nb *= -1;
		*di = *di / 10;
		(*x)++;
	}
}

static void	handle_division(long *di, long *x, long i)
{
	while (*x < i - 1)
	{
		*di = *di * 10;
		(*x)++;
	}
}

char	*ft_itoa(int n)
{
	char	*number;
	long	i;
	long	k;
	long	nb;
	long	di;

	k = 0;
	di = 1;
	nb = n;
	i = get_number_size(n);
	number = malloc ((i + 1) * (sizeof(char)));
	if (!number)
		return (NULL);
	handle_division(&di, &k, i);
	k = 0;
	handle_negative(&nb, number, &di, &k);
	while (k < i && di > 0)
	{
		number[k] = (nb / di) + '0';
		nb = nb % di;
		di = di / 10;
		k++;
	}
	number[k] = '\0';
	return (number);
}
