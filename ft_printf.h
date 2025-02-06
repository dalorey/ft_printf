/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:00:13 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/05 16:49:11 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // For va_list;
# include <unistd.h> // For write;
# include <stdlib.h> // For malloc, free;
# include "Libft/libft.h"

int	ft_printf(const char *data, ...);

#endif