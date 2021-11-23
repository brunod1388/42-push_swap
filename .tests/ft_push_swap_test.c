/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:30:50 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/22 19:07:32 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_dlist *a;
	t_dlist *b;
	int		*pi;
	
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
	ft_printdlsti(a, 0, ft_isbigger);
	ft_printf("----------------------------------------\n");
	ft_printf("Init a and b:\n");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec sa:\n");
	do_op(a, b, "sa");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec pb pb pb\n");
	do_op(a, b, "pb");
	print_stacks(a, b);

	do_op(a, b, "pb");
	print_stacks(a, b);

	do_op(a, b, "pb");	do_op(a, b, "pb");
	print_stacks(a, b);

	do_op(a, b, "pb");	do_op(a, b, "pb");
	do_op(a, b, "pb");	do_op(a, b, "pb");
	do_op(a, b, "pb");	do_op(a, b, "pb");
	do_op(a, b, "pb");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec ra rb\n");
	do_op(a, b, "rr");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec rra rrb\n");
	do_op(a, b, "rrr");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec sa:\n");
	do_op(a, b, "sa");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec pa pa pa\n");
	do_op(a, b, "pb");
	do_op(a, b, "pb");
	do_op(a, b, "pb");
	print_stacks(a, b);

}
