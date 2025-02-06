/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:58:46 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/06 17:32:24 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.c"
#include <stdio.h> // For printf --- DELETE ME;

int	ft_printf(const char *data, ...)
{

	ft_putchar_fd((char)data[0], 1);
	return (ft_strlen(data));
}