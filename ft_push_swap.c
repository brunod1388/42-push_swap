/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:50:28 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/11 04:25:22 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	if (argc == 2)
		stacks.a = ft_sttodl(argv[1]);
	else
		stacks.a = ft_atodl(argc, argv);
	stacks.b = ft_dlnew();
	stacks.solution = ft_dlnew();
	if (!stacks.a || !stacks.b || !ft_isdlok(stacks.a))
		ft_putstr("Error\n");
	else
		ft_solve(&stacks);
	ft_printsol(&stacks);
	ft_dlclear(&stacks.a);
	ft_dlclear(&stacks.b);
	ft_dlclear(&stacks.solution);
	return (0);
}
