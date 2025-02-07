/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:00:13 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/07 20:11:58 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // For va_list, va_start, va_arg, va_end;
# include <unistd.h> // For write;
# include <stdlib.h> // For malloc, free;
# include "Libft/libft.h"

int	ft_printf(const char *data, ...);
int	ft_num_len(int num);

#endif