/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:34:56 by navera-m          #+#    #+#             */
/*   Updated: 2024/10/21 13:36:03 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (ptr == NULL && ptr2 == NULL)
		return (dest);
	if (dest == src || !n)
		return (dest);
	while (n > i)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dest);
}
