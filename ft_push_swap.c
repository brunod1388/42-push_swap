/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:30:50 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/09 18:23:52 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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
