/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:41:26 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/02/26 16:34:22 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int	numchar;
	int	ft_numchar;

	printf("\033[35m---[Hello Main]---\033[0m\n");

	// Test characters
	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf(" %c %c %c\n", 'A', 'B', 'C');
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf(" %c %c %c\n", 'A', 'B', 'C');
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf(" %c %% %c\n", 'D', 'E');
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf(" %c %% %c\n", 'D', 'E');
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	// Test integers
	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf("Number: %d\n", 42);
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf("Number: %d\n", 42);
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	// Test unsigned integers
	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf("Unsigned: %u\n", -1);
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf("Unsigned: %u\n", -1);
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf(" %u %u %u %u %u %u %u\n",
		INT_MAX, INT_MIN, (unsigned int)LONG_MAX,
		(unsigned int)LONG_MIN, (unsigned int)ULONG_MAX, 0, -42);
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf(" %u %u %u %u %u %u %u\n",
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	// Test strings
	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf("Hello, %s!\n", "world");
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf("Hello, %s!\n", "world");
	ft_printf("Number of chars: '%d'\n", ft_numchar);
	// Test NULL string argument
	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf(" NULL %s NULL \n", (char *) NULL);
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf(" NULL %s NULL \n", (char *) NULL);
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	// Test hexadecimal 'x' or 'X'
	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf("Hex: %x\n", 42);
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf("Hex: %x\n", 42);
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf("Hex: %x\n", (unsigned int) LONG_MAX);
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf("Hex: %x\n", (unsigned int) LONG_MAX);
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf("Hex: %x\n", (unsigned int) LONG_MIN);
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf("Hex: %x\n", (unsigned int) LONG_MIN);
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf("Hex: %x\n", (unsigned int) ULONG_MAX);
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf("Hex: %x\n", (unsigned int) ULONG_MAX);
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf("Hex: %x\n", (unsigned int) 9223372036854775807LL);
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf("Hex: %x\n", (unsigned int) 9223372036854775807LL);
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN,
		(unsigned int)LONG_MAX, (unsigned int)LONG_MIN,
		(unsigned int)ULONG_MAX, 0, -42);
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN,
		LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	// Test pointers
	int	num = 42;
	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf("Pointer: %p\n", &num);
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf("Pointer: %p\n", &num);
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	printf("\033[32m   +++[printf]+++\033[0m\n");
	numchar = printf("Pointer: %p\n", (void *)-42);
	printf("Number of chars: '%d'\n", numchar);
	printf("\033[34m   ***[ft_printf]***\033[0m\n");
	ft_numchar = ft_printf("Pointer: %p\n", (void *)-42);
	ft_printf("Number of chars: '%d'\n", ft_numchar);

	printf("\033[31m---[Bye Main]---\033[0m\n");
	return (0);
}
