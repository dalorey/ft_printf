/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:58:46 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/05 17:31:05 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.c"

int	ft_printf(const char *data, ...)
{
	char	letter;

	letter = data[0];
	ft_putchar_fd(letter, 1);
	return (1);
}