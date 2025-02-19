/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:42:04 by navera-m          #+#    #+#             */
/*   Updated: 2024/11/26 16:43:01 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	lastc;
	int		i;

	p = NULL;
	lastc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == lastc)
			p = (char *)&s[i];
		s--;
		i++;
		if (s[i] == '\0')
			s--;
		i++;
	}
	if (s[i] == lastc)
		p = (char *)&s[i];
	return (p);
}

/* int main (void)
{
	char	p[] = "la\0las\0lt";
	char	c = 'l';
	char	*r;

	r = ft_strrchr(p, c);
	printf("%s\n", r);
	return (0);
} */