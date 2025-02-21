/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcionesprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:32:14 by navera-m          #+#    #+#             */
/*   Updated: 2025/02/21 16:26:52 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharprint(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlenprint(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstrprint(char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbrprint(int n)
{
	int	bytes;
	int	x;

	x = n;
	bytes = 0;
	if (n <= 0)
	{
		bytes++;
			if (n == -2147483648)
			{
				write(1, "-2", 2);
				bytes++;
				n = 147483648;
				x = n;
			}
			else
				x = n * -1;
	}
	while (x > 0)
	{
		x = x / 10;
		bytes = bytes + 1;
	}
	ft_putnbr_fd(n, 1);
	return (bytes);
}

int	ft_putpointerprint(long unsigned int pointer)
{
	int	address;

	address = 0;
	if (!pointer)
			address += ft_putstrprint("(nil)");
	else
	{
		write(1, "0x", 2);
		address = 2;
		address += ft_puthex(pointer, 16, "0123456789abcdef");
	}
	return (address);
}

int	ft_putdec(unsigned int num)
{
	int	bytes;

	bytes = 0;
	if (num == 0)
		bytes += ft_putcharprint('0');
	else
	{
		if (num >= 10)
			ft_putdec(num / 10);
		ft_putcharprint((num % 10) + 48);
		while (num)
		{
			num = num / 10;
			bytes++;
		}
	}
	return (bytes);
}

int	ft_puthex(unsigned long int dec, unsigned int basehex, char *digitoshex)
{
	int bytes;

	bytes = 0;
	if (dec >= basehex)
	{
		bytes += ft_puthex(dec / basehex, basehex, digitoshex);
	}
	bytes += ft_putcharprint(digitoshex[dec % basehex]);
	return (bytes);
}
