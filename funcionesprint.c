/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcionesprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:32:14 by navera-m          #+#    #+#             */
/*   Updated: 2025/02/19 15:31:49 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/libft.h"

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
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbrprint(int n)
{
	int	bytes;
	int x;

	x = n;
	bytes = 0;
	while (x > 0)
	{
		x = x / 10;
		bytes = bytes + 1;
	}
	if (n < 0)
		bytes++;
	ft_putnbr_fd(n, 1);
	return (bytes);
}

int	ft_putpointerprint(unsigned int *pointer) /*usarunsignedintbcitisahex*/
{
	int	address;

	address = 0;
	if (pointer == 0)
			address += ft_putstrprint("(NULL)");/*paraescribir*/
	else
	{
		address += write(1, "0x", 2);/*paraescribir*/
		address += ft_puthex(*pointer, 16, "0123456789abcdef");
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
		if (num / 10)
			ft_putdec(num / 10);
		ft_putcharprint((num % 10) + '0'); /* suma el valor 0(48)ascii*/
		while (num > 10)
		{
			num = num / 10;
			bytes++;
		}
	}
	return (bytes);
}

int	ft_puthex(unsigned int dec, unsigned int basehex, char *digitoshex)
{
	int bytes;

	bytes = 0;
	if (dec >= basehex)
	{
		bytes += ft_puthex(dec, basehex, digitoshex);
		bytes += ft_putcharprint(digitoshex[dec % basehex]);
	}
	return (bytes);
}
