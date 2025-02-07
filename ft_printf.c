/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:58:46 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/07 22:45:02 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // For printf --- DELETE ME;

// int	ft_printf(const char *data, ...) // Basic ft_printf function
// {
// 	ft_putchar_fd((char)data[0], 1);
// 	return (ft_strlen(data));
// }

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
				ft_putstr_fd(str, 1);
				numchar += ft_strlen(str);
			}
			if (*data == 'p')
			{
				ptr = va_arg(args, void *);
				ft_putstr_fd("0x", 1);
				numchar += 2;
				// ft_putptr_fd(ptr, 1);
				// numchar += 2 + ft_strlen(ptr);
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
				if (unum < 0)
					unum = -unum;
				ft_putnbr_fd(unum, 1);
				numchar += ft_num_len(unum);
			}
		}
		else
		{
			ft_putchar_fd(*data, 1);
			numchar++;
		}
		data++;
	}
	return (numchar);
}
