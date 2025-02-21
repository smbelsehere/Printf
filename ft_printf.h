/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:11 by navera-m          #+#    #+#             */
/*   Updated: 2025/02/21 12:58:51 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
//# include <stdio.h>
//# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_putcharprint(char c);
int	format(char c, va_list args);
size_t	ft_strlenprint(const char *s);
int	ft_putstrprint(char *s);
int	ft_putnbrprint(int n);
int	ft_putpointerprint(long unsigned int pointer);
int	ft_putdec(unsigned int num);
int	ft_puthex(unsigned long int dec, unsigned int basehex, char *digitoshex);

#endif