/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:52:39 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/10 02:15:17 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_iscommand(char *s)
{
	if (!ft_strncmp(s, SA, 2))
		return (1);
	if (!ft_strncmp(s, SB, 2))
		return (1);
	if (!ft_strncmp(s, PA, 2))
		return (1);
	if (!ft_strncmp(s, PB, 2))
		return (1);
	if (!ft_strncmp(s, RA, 2))
		return (1);
	if (!ft_strncmp(s, RB, 2))
		return (1);
	if (!ft_strncmp(s, RR, 2))
		return (1);
	if (!ft_strncmp(s, RRA, 3))
		return (1);
	if (!ft_strncmp(s, RRB, 3))
		return (1);
	if (!ft_strncmp(s, RRR, 3))
		return (1);
	return (0);
}

void	ft_getsol(t_stacks *stacks)
{
	char	*op;

	op = get_next_line(0);
	while (ft_iscommand(op))
	{
		op[ft_strlen(op) - 1] = 0;
		ft_dladdlast(stacks->solution, op);
		op = get_next_line(0);
	}
}

void	ft_apply_sol(t_stacks *stacks)
{
	t_dlist	*solution;
	t_node	*current;
	char	*op;

	solution = stacks->solution;
	stacks->solution = ft_dlnew();
	current = solution->first;
	while (current)
	{
		op = (char *)current->content;
		do_op(stacks, op);
		current = current->next;
	}
}

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
	if (!stacks.a || !stacks.b || !stacks.solution || !ft_isdlok(stacks.a))
		ft_putstr("Error\n");

	print_stacks(&stacks);
	ft_getsol(&stacks);
	ft_printsol(&stacks);
	ft_apply_sol(&stacks);
	print_stacks(&stacks);
	ft_dlclear(&stacks.a);
	ft_dlclear(&stacks.b);
	ft_dlclear(&stacks.solution);
	while (1);
	return (0);
}
