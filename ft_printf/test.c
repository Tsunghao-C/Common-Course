/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:22:05 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/17 17:54:05 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	printf("\\ \a \t %+d\n", 23);
	printf("abc\176abd\1738`32-\n");
	printf("Hello, world!\n");
	printf("Octal 141: \141\n");     // This will print 'a'
	printf("Octal 101: \101\n");     // This will print 'A'
	printf("Hexadecimal 61: \x61\n"); // This will print 'a'
	printf("Hexadecimal 41: \x41\n"); // This will print 'A'
	return (0);
}
