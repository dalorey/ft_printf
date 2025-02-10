/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:58:46 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/10 20:49:50 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_args(t_args *args, va_list input)
{
	if (args->flag == 'c' || args->flag == 'd' || args->flag == 'i')
		args->num = va_arg(input, int);
	else if (args->flag == 'p' || args->flag == 's')
		args->ptr = va_arg(input, void *);
	else if (args->flag == 'u' || args->flag == 'x' || args->flag == 'X')
		args->unum = va_arg(input, unsigned int);
}

int	ft_handle_chars(t_args args)
{
	if (args.flag == 'c')
	{
		return (ft_putchar_fd(args.num, 1), ++args.len);
	}
	else if (args.flag == 's')
	{
		if (!(char *)args.ptr)
			args.ptr = (char *)"(null)";
		ft_putstr_fd((char *)args.ptr, 1);
		return (args.len += ft_strlen((char *)args.ptr));
	}
	else if (args.flag == '%')
	{
		return (ft_putchar_fd('%', 1), ++args.len);
	}
	return (0);
}

int	ft_handle_hex(t_args args)
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
			return (ft_putstr_fd("(nil)", 1), args.len += 5);
		else
		{
			ft_putstr_fd("0x", 1);
			ft_putnbr_base_fd((unsigned long long)args.ptr,
				"0123456789abcdef", 1);
			return (args.len += ft_hex_len((unsigned long long)args.ptr) + 2);
		}
	}
	return (0);
}

int	ft_get_data(t_args args)
{
	if (args.flag == 'c' || args.flag == 's' || args.flag == '%')
		return (ft_handle_chars(args));
	else if (args.flag == 'd' || args.flag == 'i')
	{
		ft_putnbr_fd(args.num, 1);
		return (args.len += ft_num_len(args.num));
	}
	else if (args.flag == 'u')
	{
		ft_putnbr_unsigned_fd(args.unum, 1);
		return (args.len += ft_unsigned_num_len(args.unum));
	}
	else if (args.flag == 'x' || args.flag == 'X' || args.flag == 'p')
		return (ft_handle_hex(args));
	return (0);
}

int	ft_printf(const char *data, ...)
{
	t_args			args;

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
			ft_parse_args(&args, args.input);
			args.len = ft_get_data(args);
		}
		else
		{
			ft_putchar_fd(*data, 1);
			args.len++;
		}
		data++;
	}
	return (va_end(args.input), args.len);
}
