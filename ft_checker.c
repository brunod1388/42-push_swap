/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:52:39 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/11 04:27:05 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <fcntl.h>

int	ft_iscommand(char *s)
{
	if (!ft_strcmp(s, SA))
		return (1);
	if (!ft_strcmp(s, SB))
		return (1);
	if (!ft_strcmp(s, SS))
		return (1);
	if (!ft_strcmp(s, PA))
		return (1);
	if (!ft_strcmp(s, PB))
		return (1);
	if (!ft_strcmp(s, RA))
		return (1);
	if (!ft_strcmp(s, RB))
		return (1);
	if (!ft_strcmp(s, RR))
		return (1);
	if (!ft_strcmp(s, RRA))
		return (1);
	if (!ft_strcmp(s, RRB))
		return (1);
	if (!ft_strcmp(s, RRR))
		return (1);
	return (0);
}

void	ft_printsol_fd(t_stacks *stacks, int fd)
{
	t_node	*current;

	current = stacks->solution->first;
	while (current)
	{
		ft_putstr_fd(current->content, fd);
		ft_putstr_fd("\n", fd);
		current = current->next;
	}
}

void	ft_getsol(t_stacks *stacks)
{
	char	*op;
	int		fd;

	fd = open("sol_txt", O_WRONLY);
	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		ft_putstr_fd(op, fd);
		op[ft_strlen(op) - 1] = 0;
		if (!ft_iscommand(op))
			break ;
		ft_dladdlast(stacks->solution, op);
	}
	if (op && op[0])
	{
		ft_dlclear(&stacks->solution);
		free(op);
	}
	close(fd);
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
	ft_dlclear(&solution);
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
	ft_getsol(&stacks);
	if (!stacks.a || !stacks.b || !stacks.solution || !ft_isdlok(stacks.a))
		ft_putstr("Error\n");
	else
		ft_apply_sol(&stacks);
	if (stacks.solution && ft_dlisordered(stacks.a, ft_isbigger))
		ft_printf("OK\n");
	else if (stacks.solution)
		ft_printf("KO\n");
	ft_dlclear(&stacks.a);
	ft_dlclear(&stacks.b);
	ft_dlclear(&stacks.solution);
	return (0);
}
