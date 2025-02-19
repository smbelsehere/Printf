/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:55:41 by navera-m          #+#    #+#             */
/*   Updated: 2024/11/14 14:50:21 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s1;

	s1 = malloc(ft_strlen(s) + 1);
	if (!s1)
		return (NULL);
	s1 = ft_memmove(s1, s, ft_strlen(s) + 1);
	return (s1);
}
