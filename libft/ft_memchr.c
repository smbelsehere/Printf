/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:39:36 by navera-m          #+#    #+#             */
/*   Updated: 2024/11/12 13:54:33 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	letra;
	size_t			i;

	s1 = (unsigned char *)s;
	letra = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == letra)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
