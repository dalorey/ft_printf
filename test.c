/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:56:24 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/07 22:41:31 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // For printf;
#include "ft_printf.h"

// int	real_printf(const char *data, ...)
// {
// 	int	numchar;

// 	numchar = 0;
// 	// numchar = printf("%c", (char)data[0]); // Print a single character
// 	// numchar = printf("%s", data); // Print a string
// 	return (numchar);
// }

int	fake_printf(const char *data, ...)
{
	int	numchar;

	numchar = 0;
	printf("\033[36m"); // Cyan text
	// numchar = ft_printf((char)data[0]); // Print a single character
	numchar = ft_printf(data); // Print a string
	return (numchar);
}

int	main(void)
{
	int				numchar;
	int				ft_numchar;
	char			*str0 = "42 is the ASCII code for *. So lucky Dani!";
	// char			*str = "Hello, %s! I learned you are %i years old.";
	// char			letter = 'H';
	// char			*name = "Laura";
	// void			*ptr = &name;
	// int				num = -25;
	// unsigned int	unum = 42;
	// char			per = '%';

	printf("\033[35m---[Hello Main]---\033[0m\n"); // Magenta text
	printf("   Test String used: '%s'\n", str0);

    printf("\033[32m   +++[printf]+++\033[0m\n"); // Green text
	printf("\033[33m"); // Yellow text
	// numchar = real_printf(str0);
	// numchar = real_printf(str, name, unum);
	numchar = printf("%s", str0);
	// numchar = printf(str, name, unum);
	printf("\nNumber of print chars: '%u'\n", numchar);
	printf("\033[0m");

    printf("\033[34m   ***[ft_printf]***\033[0m\n");  // Blue text
	printf("\033[36m"); // Cyan text
	ft_numchar = fake_printf(str0);
	// ft_numchar = fake_printf(str, name, unum);
	printf("\nNumber of ft_print chars: '%u'\n", ft_numchar);
	printf("\033[0m");

	printf("\033[31m---[Bye Main]---\033[0m\n");   // Red text

	return (0);
}
