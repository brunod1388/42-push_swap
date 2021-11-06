/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:14:44 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/06 02:00:35 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"
#include <stdio.h>

int main (void)
{
	int n;

	n = ft_printf("a : %s\nb : %i\nc : %c\n", "a", 32, 'c');
	printf("len = %d\n", n);
	n = printf("a : %s\nb : %i\nc : %c\n", "a", 32, 'c');
	printf("len = %d\n", n);
	n = ft_printf("HELLO World y%seahhf%sasfdsf%s \n", "\n1: ", "\n2: ", "\n3: ");
	printf("len = %d\n", n);
	n = printf("HELLO World y%seahhf%sasfdsf%s \n", "\n1: ", "\n2: ", "\n3: ");
	printf("len = %d\n", n);

	ft_printf("int : \n");
	n = ft_printf("a : %i\tb : %i\tc : %i\ta : %i\tb : %i\tc : %i\n", 
					4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);
	n = printf("a : %i\tb : %i\tc : %i\ta : %i\tb : %i\tc : %i\n",
				4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);

	ft_printf("HEX : \n");
	n = ft_printf("a : %X\tb : %X\tc : %X\ta : %X\tb : %X\tc : %X\n", 
					4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);
	n = printf("a : %X\tb : %X\tc : %X\ta : %X\tb : %X\tc : %X\n",
				4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);

	ft_printf("uint : \n");
	n = ft_printf("a : %u\tb : %u\tc : %u\ta : %u\tb : %u\tc : %u\n", 
					4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);
	n = printf("a : %u\tb : %u\tc : %u\ta : %u\tb : %u\tc : %u\n",
				4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);

	ft_printf("hex : \n");
	n = ft_printf("a : %x\tb : %x\tc : %x\ta : %x\tb : %x\tc : %x\n", 
					4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);
	n = printf("a : %x\tb : %x\tc : %x\ta : %x\tb : %x\tc : %x\n",
				4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);

	ft_printf("d : \n");
	n = ft_printf("a : %d\tb : %d\tc : %d\ta : %d\tb : %d\tc : %d\n", 
					4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);
	n = printf("a : %d\tb : %d\tc : %d\ta : %d\tb : %d\tc : %d\n",
				4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);

	n = ft_printf("a : %#s\nb : %i\nc : %c\n", "a", 32, 'c');
	printf("len = %d\n", n);

	// while(1);
	return (0);
}