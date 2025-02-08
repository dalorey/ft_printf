/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:56:24 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/08 22:57:38 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // For printf;
#include <limits.h> // For INT_MIN;
#include "ft_printf.h"

int	main(void)
{
	int				numchar;
	int				ft_numchar;
	// char			*str = NULL;
	// char			*str = "42 is the ASCII code for *. So lucky Dani!";
	// char			*str = "Hello, %s! I learned you are %i years old.";
	// char			*str = "' %u '";
	char			*str = "LONG_MIN: '%p', LONG_MAX: '%p'";
	// char			letter = 'H';
	// char			*name = "Laura";
	// void			*ptr = &name;
	// int			num = -25;
	// int			num_imax = INT_MAX;
	// unsigned int	unum = -1;
	long			long_min = LONG_MIN;
	long			long_max = LONG_MAX;
	// char			per = '%';

// ---------------------- Test data- -------------------------------------------
	printf("\033[35m---[Hello Main]---\033[0m\n"); // Magenta text
	printf("\033[36m"); // Cyan text
	printf("Test String used: \n%s\n", str);
	printf("Number of chars: '%zu'\n", ft_strlen(str));
	// printf("Test Name used: '%s'\n", name);
	// printf("Test Number used: '%u'\n", unum);
	// printf("num = %d\n", num);
	// printf("unum = %u\n", unum);
	printf("LONG_MIN = %ld\n", long_min);
	printf("LONG_MAX = %ld\n", long_max);
// ---------------------- Test printf ------------------------------------------
    printf("\033[32m   +++[printf]+++\033[0m\n"); // Green text
	printf("\033[33m"); // Yellow text
	// numchar = printf("%s", str);
	// numchar = printf(str, name, unum);
	// numchar = printf(str, num);
	// numchar = printf(str, unum);
	// numchar = printf(str, long_min, long_max);
	numchar = printf(str, 0, 0);
	printf("\nNumber of chars: '%u'\n", numchar);
// ---------------------- Test ft_printf ---------------------------------------
    printf("\033[34m   ***[ft_printf]***\033[0m\n");  // Blue text
	// ft_numchar = ft_printf(str);
	// ft_numchar = ft_printf(str, name, unum);
	// ft_numchar = ft_printf(str, num);
	// ft_numchar = ft_printf(str, unum);
	// ft_numchar = ft_printf(str, long_min, long_max);
	ft_numchar = ft_printf(str, 0, 0);
	printf("\nNumber of chars: '%u'\n", ft_numchar);
	printf("\033[31m---[Bye Main]---\033[0m\n");   // Red text
	return (0);
}
