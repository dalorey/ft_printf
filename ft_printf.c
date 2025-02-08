/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:58:46 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/08 22:55:33 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // For printf --- DELETE ME;

int	ft_printf(const char *data, ...)
{
	va_list			args;
	int				numchar;
	char			letter;
	char			*str;
	void			*ptr;
	int				num;
	unsigned int	unum;

	va_start(args, data);
	numchar = 0;
	if (!data)
		return (ft_putstr_fd("(null)", 1), 6);
	while (*data)
	{
		if (*data == '%')
		{
			data++;
			if (*data == 'c')
			{
				letter = va_arg(args, int);
				ft_putchar_fd(letter, 1);
				numchar++;
			}
			if (*data == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				ft_putstr_fd(str, 1);
				numchar += ft_strlen(str);
			}
			if (*data == 'p')
			{
				ptr = va_arg(args, void *);
				if (!ptr)
				{
					ft_putstr_fd("(nil)", 1);
					numchar += 5;
				}
				else
				{
					ft_putstr_fd("0x", 1);
					ft_putnbr_base_fd((unsigned long long)ptr,
						"0123456789abcdef", 1);
					numchar += ft_hex_len((unsigned long long)ptr) + 2;
				}
			}
			if (*data == 'd' || *data == 'i')
			{
				num = va_arg(args, int);
				ft_putnbr_fd(num, 1);
				numchar += ft_num_len(num);
			}
			if (*data == 'u')
			{
				unum = va_arg(args, unsigned int);
				ft_putnbr_unsigned_fd(unum, 1);
				numchar += ft_unsigned_num_len(unum);
			}
			if (*data == 'x')
			{
				unum = va_arg(args, unsigned int);
				ft_putnbr_base_fd(unum, "0123456789abcdef", 1);
				numchar += ft_hex_len(unum);
			}
			if (*data == 'X')
			{
				unum = va_arg(args, unsigned int);
				ft_putnbr_base_fd(unum, "0123456789ABCDEF", 1);
				numchar += ft_hex_len(unum);
			}
			if (*data == '%')
			{
				ft_putchar_fd('%', 1);
				numchar++;
			}
		}
		else
		{
			ft_putchar_fd(*data, 1);
			numchar++;
		}
		data++;
	}
	va_end(args);
	return (numchar);
}
