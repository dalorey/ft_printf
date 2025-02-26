/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:32:28 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/26 11:59:33 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // For va_list, va_start, va_arg, va_end;
# include <unistd.h> // For write;
# include <stdlib.h> // For malloc, free;
# include "libft/libft.h"

typedef struct s_args
{
	va_list				input;
	char				flag;
	int					len;
	char				letter;
	char				*str;
	void				*ptr;
	int					num;
	unsigned int		unum;
}	t_args;

int		ft_printf(const char *data, ...);
int		ft_num_len(int num);
int		ft_unsigned_num_len(unsigned int num);
int		ft_hex_len(unsigned long long num);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
void	ft_putnbr_base_fd(unsigned long long n, char *base, int fd);

#endif