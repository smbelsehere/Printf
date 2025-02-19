/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:55:13 by navera-m          #+#    #+#             */
/*   Updated: 2024/10/21 13:47:28 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	unsigned int	i;
	long			a;
	long			symb;

	i = 0;
	a = 0;
	symb = 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\f'
		|| s[i] == '\r' || s[i] == '\v')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			symb = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		a = a * 10 + s[i] - '0';
		i++;
	}
	return ((int)(a * symb));
}
