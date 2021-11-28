/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 03:20:19 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/28 03:26:56 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_int_array(int arr[], int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_printf("%d ", arr[i++]);
	ft_putchar('\n');
}
