/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:11:17 by navera-m          #+#    #+#             */
/*   Updated: 2024/11/14 14:54:33 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_integer(int n)
{
	int	x;

	x = 0;
	if (n < 0)
		x++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		x++;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		j;

	i = ft_integer(n);
	if (n == -2147483648)
		return (s = ft_strdup("-2147483648"), s);
	else if (n == 0)
		return (s = ft_strdup("0"), s);
	s = ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (free(s), NULL);
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
	}
	j = 0;
	while (n != 0)
	{
		j = n % 10;
		n = n / 10;
		s[--i] = j + 48;
	}
	return (s);
}
