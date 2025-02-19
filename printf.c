/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:13:20 by navera-m          #+#    #+#             */
/*   Updated: 2025/02/19 15:28:58 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"

int	format(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
			i += ft_putcharprint(va_arg(args, int));
	else if (c == 's')
			i += ft_putstrprint(va_arg(args, char *));
	else if (c == 'p')
			i += ft_putpointerprint(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
			i += ft_putnbrprint(va_arg(args, int));
	else if (c == 'u')
			i += ft_putdec(va_arg(args, unsigned int));
	else if (c == 'x')
			i += ft_puthex(va_arg(args, unsigned int), 16, "0123456789abcdef");
	else if (c == 'X')
			i += ft_puthex(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
	else if (c == '%')
			i += ft_putcharprint('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			count += format(s[++i], args);
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}



/* int main (void)
{
	const char *k;
	
	k = "hola 42, 10C6"; falta anadir Nao, chequea la guia
	printf("%s\n", k);
	return (0);
} */

