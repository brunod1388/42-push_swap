/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:30:50 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/08 01:06:47 by bgoncalv         ###   ########.fr       */
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
	if (argc == 2)
		a = ft_sttodl(argv[1]);
	else
		a = ft_atodl(argc, argv);
	b = ft_dlnew();
	if (!a || !b || !ft_isdlok(a))
		ft_putstr("Error\n");
	else
		ft_solve(a, b);
	ft_dlclear(&a);
	ft_dlclear(&b);
	return (0);
}
