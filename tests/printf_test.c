/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:14:44 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/03 00:51:59 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int main (void)
{
	int n;
	
	n = ft_printf("HELLO World y%eahhf%asfdsf%\n", "\n1: ", "\n2: ", "\n3: ");
	printf("len = %d\n", n);
	while(1);
	return (0);
}