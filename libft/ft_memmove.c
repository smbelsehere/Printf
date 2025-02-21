/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:31:17 by navera-m          #+#    #+#             */
/*   Updated: 2024/11/25 14:19:45 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*o;
	char	*d;
	size_t	i;

	o = (void *)src;
	d = (void *)dest;
	i = 0;
	if (!n || d == o)
		return (dest);
	if (d > o)
	{
		while (n-- > 0)
			d[n] = o[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = o[i];
			i++;
		}
	}
	return (dest);
}
