/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:56:24 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/05 16:50:23 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // For printf;
#include "ft_printf.h"

int	real_printf(const char *data, ...)
{
	int	numchar;

	numchar = printf("%s", (char *)data);
	return (numchar);
}

int	fake_printf(const char *data, ...)
{
	int	numchar;

	numchar = ft_printf((char *)data);
	return (numchar);
}

int	main(void)
{
	static char	*str = "42 is the ASCII code for *. So lucky Dani!";
	int			print_numchar;
	int			ft_print_numchar;

	printf("\033[35m---[Hello Main]---\033[0m\n"); // Magenta text
	printf("   Test String used: '%s'\n", str); // Normal white text

    printf("\033[32m   +++[printf]+++\033[0m\n"); // Green text
	printf("\033[33m"); // Start Yellow
	print_numchar = real_printf(str);
	printf("\nNumber of print chars: '%u'\n", print_numchar);
    printf("\033[0m"); // Back to white

    printf("\033[34m   ***[ft_printf]***\033[0m\n");  // Blue text
	printf("\033[36m"); // Start Cyan
	ft_print_numchar = fake_printf(str);
	printf("\nNumber of ft_print chars: '%u'\n", ft_print_numchar);
    printf("\033[0m"); // Back to white

	printf("\033[31m---[Bye Main]---\033[0m\n");   // Red text

	// real_printf(str);
	// fake_printf(str);
	return (0);
}
