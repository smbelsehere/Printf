/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:52:58 by navera-m          #+#    #+#             */
/*   Updated: 2024/11/28 20:03:16 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (big[i] && len--)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && j <= len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/* #include <string.h>

int	main(void)
{
	char *s1 = "see FF your FF return FF now FF";
	char *s2 = "FF";
	size_t max = strlen(s1);
	char *i1;
	i1 = strnstr(s1, s2, max);
	char *i2 = ft_strnstr(s1, s2, max);
	printf("origi: %s\n", i1);
	printf("naomi: %s", i2);
	return (0);
} */
