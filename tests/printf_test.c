/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:14:44 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/07 21:28:15 by bgoncalv         ###   ########.fr       */
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
	n =    printf("a : %s\nb : %i\nc : %c\n", "a", 32, 'c');
	printf("len = %d\n\n", n);

	n = ft_printf("HELLO World y%seahhf%sasfdsf%s \n", "\n1: ", "\n2: ", "\n3: ");
	printf("len = %d\n", n);
	n =    printf("HELLO World y%seahhf%sasfdsf%s \n", "\n1: ", "\n2: ", "\n3: ");
	printf("len = %d\n\n", n);
	//
	//       NO FLAGS TEST
	//
	// ft_printf("int : \n");
	// n = ft_printf("a : %i\tb : %i\tc : %i\ta : %i\tb : %i\tc : %i\n", 
	// 				4528, 32, -538609, 0, -5, 8737853);
	// printf("len = %d\n", n);
	// n = printf("a : %i\tb : %i\tc : %i\ta : %i\tb : %i\tc : %i\n",
	// 			4528, 32, -538609, 0, -5, 8737853);
	// printf("len = %d\n", n);

	// ft_printf("HEX : \n");
	// n = ft_printf("a : %X\tb : %X\tc : %X\ta : %X\tb : %X\tc : %X\n", 
	// 				4528, 32, -538609, 0, -5, 8737853);
	// printf("len = %d\n", n);
	// n = printf("a : %X\tb : %0X\tc : %X\ta : %X\tb : %X\tc : %X\n",
	// 			4528, 32, -538609, 0, -5, 8737853);
	// printf("len = %d\n", n);

	// ft_printf("uint : \n");
	// n = ft_printf("a : %u\tb : %u\tc : %u\ta : %u\tb : %u\tc : %u\n", 
	// 				4528, 32, -538609, 0, -5, 8737853);
	// printf("len = %d\n", n);
	// n = printf("a : %u\tb : %u\tc : %u\ta : %u\tb : %u\tc : %u\n",
	// 			4528, 32, -538609, 0, -5, 8737853);
	// printf("len = %d\n", n);

	// ft_printf("hex : \n");
	// n = ft_printf("a : %x\tb : %x\tc : %x\ta : %x\tb : %x\tc : %x\n", 
	// 				4528, 32, -538609, 0, -5, 8737853);
	// printf("len = %d\n", n);
	// n = printf("a : %x\tb : %x\tc : %x\ta : %x\tb : %x\tc : %x\n",
	// 			4528, 32, -538609, 0, -5, 8737853);
	// printf("len = %d\n", n);

	// ft_printf("d : \n");
	// n = ft_printf("a : %d\tb : %d\tc : %d\ta : %d\tb : %d\tc : %d\n", 
	// 				4528, 32, -538609, 0, -5, 8737853);
	// printf("len = %d\n", n);
	// n = printf("a : %d\tb : %d\tc : %d\ta : %d\tb : %d\tc : %d\n",
	// 			4528, 32, -538609, 0, -5, 8737853);
	// printf("len = %d\n", n);


	//
	//		FLAGS test
	//
	ft_printf("int : \n");
	n = ft_printf("a : %+.3i\tb : %+.54i\tc : %+.12i\ta : %.0i\tb : %-20.1i\tc : % -20.5i\n", 
					4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);
	n = printf("a : %+.3i\tb : %+.54i\tc : %+.12i\ta : %.0i\tb : % -20.1i\tc : % -20.5i\n",
				4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n\n", n);

	ft_printf("HEX : \n");
	n = ft_printf("a : %.5X\tb : %.4X\tc : %.2X\ta : %.7X\tb : %.0X\tc : %.23X\n", 
					4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);
	n = printf("a : %.5X\tb : %.4X\tc : %.2X\ta : %.7X\tb : %.0X\tc : %.23X\n",
				4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n\n", n);

	ft_printf("uint : \n");
	n = ft_printf("a : %u\tb : %u\tc : %u\ta : %u\tb : %u\tc : %u\n", 
					4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);
	n = printf("a : %u\tb : %u\tc : %u\ta : %u\tb : %u\tc : %u\n",
				4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n\n", n);

	ft_printf("hex : \n");
	n = ft_printf("a : %x\tb : %x\tc : %x\ta : %x\tb : %x\tc : %-20x\n", 
					4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);
	n = printf("a : %x\tb : %x\tc : %x\ta : %x\tb : %x\tc : %-20x\n",
				4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n\n", n);

	ft_printf("d : \n");
	n = ft_printf("a : %d\tb : %d\tc : %d\ta : %d\tb : %d\tc : %d\n", 
					4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n", n);
	n = printf("a : %d\tb : %d\tc : %d\ta : %d\tb : %d\tc : %d\n",
				4528, 32, -538609, 0, -5, 8737853);
	printf("len = %d\n\n", n);

	ft_printf("str : \n");
	n = ft_printf("a : %s\tb : %.10s\tc : %.2s\ta : %-5.1s\tb : %10.50s\tc : %-20.10s\n",
				"4528", "32", "538609", "0", "", "8737853");
	printf("len = %d\n", n);

	n = printf("a : %s\tb : %.10s\tc : %.2s\ta : %-5.1s\tb : %10.50s\tc : %-20.10s\n",
				"4528", "32", "538609", "0", "", "8737853");
	printf("len = %d\n\n", n);

	ft_printf("char : \n");
	n = ft_printf("a : %c\tb : %c\tc : %c\ta : %c\tb : %c\tc : %c\n",
				'a', 'b', 'c', ' ', ' ', 'c');
	printf("len = %d\n", n);

	n = printf("a : %c\tb : %c\tc : %c\ta : %c\tb : %c\tc : %c\n",
				'a', 'b', 'c', ' ', ' ', 'c');
	printf("len = %d\n\n", n);


	// n = ft_printf("a : %20%\nb : %-10%\nc : %%\n");
	// printf("len = %d\n", n);

	// n =    printf("a : %20%\nb : %-10%\nc : %%\n");
	// printf("len = %d\n", n);

	// n = ft_printf("final test : %.20d\n\n", -32);
	// printf("len = %d\n", n);
	// n = printf("final test : %.20d\n\n", -32);
	// printf("len = %d\n", n);

	// printf("%d\n", 32);
	// printf("% .53d\n", 32);
	// printf("%+.53d\n", -32);
	// printf("% .53d\n", -32);

	// printf("%#x\n", 55);
	// printf("%#X\n", 55);
	// printf("%.3s.\n", "salut");
	// printf("%-20s.\n", "salut");

	// n = ft_printf("test : %s\n", "test");
	// printf("len = %d\n", n);
	// n = printf("test : %s\n", "test");
	// printf("len = %d\n", n);


	// while(1);
	return (0);
}