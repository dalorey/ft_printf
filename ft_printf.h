/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:00:13 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/10 20:51:54 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // For va_list, va_start, va_arg, va_end;
# include <unistd.h> // For write;
# include <stdlib.h> // For malloc, free;
# include "Libft/libft.h"

typedef struct s_args
{
	va_list			input;
	char			flag;
	int				len;
	// char			letter;	// use int for letter
	// char			*str;	// use void * for str
	void			*ptr;
	int				num;
	unsigned int	unum;
}	t_args;

int		ft_printf(const char *data, ...);
int		ft_num_len(int num);
int		ft_unsigned_num_len(unsigned int num);
int		ft_hex_len(unsigned long long num);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
void	ft_putnbr_base_fd(unsigned long long n, char *base, int fd);

#endif