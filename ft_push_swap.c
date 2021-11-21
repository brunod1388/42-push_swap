/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:30:50 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/22 00:53:50 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_push_swap.h"

int	main(int argc, char **argv)
{	
	int i;
	t_dlist *a;
	t_dlist *b;
	int	*pi;
	
	if (argc < 3)
	{
		ft_printf("enter at least two args\n");
		return (0);
	}
	i = 0;
	a = ft_dlnew();
	b = ft_dlnew();
	while (argc-- > 1)
	{
		pi = malloc(sizeof(int));
		*pi = ft_atoi(argv[argc]);
		ft_dladdfirst(a, pi);
	}
	ft_printdlsti(a, 0);
	ft_printf("----------------------------------------\n");
	ft_printf("Init a and b:\n");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec sa:\n");
	elswap(a);
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec pb pb pb\n");
	elpush(b, a);
	elpush(b, a);
	elpush(b, a);
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec ra rb\n");
	elrotate(a);
	elrotate(b);
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec rra rrb\n");
	elreverse(a);
	elreverse(b);
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec sa:\n");
	elswap(a);
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec pa pa pa\n");
	elpush(a, b);
	elpush(a, b);
	elpush(a, b);
	print_stacks(a, b);

}
