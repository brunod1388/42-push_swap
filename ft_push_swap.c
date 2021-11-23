/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:30:50 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/23 21:45:22 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;

	if (argc == 1)
		return (0);
	a = ft_atodl(argc, argv);
	b = ft_dlnew();
	if (!a)
	{
		ft_putstr("Error\n");
		return (0);
	}
	print_stacks(a, b);
	ft_dlclear(&a);
	ft_dlclear(&b);
	return (0);
}
