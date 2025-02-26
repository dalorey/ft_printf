/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:40:45 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/26 15:56:26 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // For printf - DELETE!!!

void	ft_parse_args(t_args *args)
{
	if (args->flag == 'c')
		args->letter = va_arg(args->input, int);
	else if (args->flag == 'd' || args->flag == 'i')
		args->num = va_arg(args->input, int);
	else if (args->flag == 'u')
		args->unum = va_arg(args->input, unsigned int);
	else if (args->flag == 's')
		args->str = va_arg(args->input, char *);
	else if (args->flag == 'x' || args->flag == 'X')
		args->unum = va_arg(args->input, unsigned int);
	else if (args->flag == 'p')
		args->ptr = va_arg(args->input, void *);
}

int	ft_print_chars(t_args args)
{
	if (args.flag == '%')
		return (ft_putchar_fd('%', 1), ++args.len);
	else if (args.flag == 'c')
		return (ft_putchar_fd(args.letter, 1), ++args.len);
	else if (args.flag == 's')
	{
		if (!args.str)
			args.str = "(null)";
		ft_putstr_fd(args.str, 1);
		return (args.len += ft_strlen(args.str));
	}
	return (0);
}

int	ft_print_hex(t_args args)
{
	if (args.flag == 'x')
	{
		ft_putnbr_base_fd(args.unum, "0123456789abcdef", 1);
		return (args.len += ft_hex_len(args.unum));
	}
	else if (args.flag == 'X')
	{
		ft_putnbr_base_fd(args.unum, "0123456789ABCDEF", 1);
		return (args.len += ft_hex_len(args.unum));
	}
	else if (args.flag == 'p')
	{
		if (!args.ptr)
		{
			ft_putstr_fd("(nil)", 1);
			return (args.len += 5);
		}
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd((unsigned long long)args.ptr, "0123456789abcdef", 1);
		return (args.len += 2 + ft_hex_len((unsigned long long)args.ptr));
	}
	return (0);
}

int	ft_print_data(t_args args)
{
	if (args.flag == 'c' || args.flag == '%' || args.flag == 's')
		return (ft_print_chars(args));
	else if (args.flag == 'd' || args.flag == 'i')
		return (ft_putnbr_fd(args.num, 1), args.len += ft_num_len(args.num));
	else if (args.flag == 'u')
		return (ft_putnbr_unsigned_fd(args.unum, 1),
			args.len += ft_unsigned_num_len(args.unum));
	else if (args.flag == 'x' || args.flag == 'X' || args.flag == 'p')
		return (ft_print_hex(args));
	return (0);
}

int	ft_printf(const char *data, ...)
{
	t_args	args;

	va_start(args.input, data);
	args.len = 0;
	if (!data)
		return (ft_putstr_fd("(null)", 1), 6);
	while (*data)
	{
		if (*data == '%')
		{
			data++;
			args.flag = *data;
			ft_parse_args(&args);
			args.len = ft_print_data(args);
		}
		else
		{
			ft_putchar_fd(*data, 1);
			args.len++;
		}
		data++;
	}
	va_end(args.input);
	return (args.len);
}
