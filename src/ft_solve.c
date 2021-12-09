/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:03:49 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/09 17:48:48 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_solve2(t_stacks *stacks)
{
	if (ft_isbigger(stacks->a->first, stacks->a->last))
		do_op(stacks, SA);
}

void	ft_solve3(t_stacks *stacks)
{
	t_node	*first;
	t_node	*mid;
	t_node	*last;

	first = stacks->a->first;
	mid = stacks->a->first->next;
	last = stacks->a->last;
	if (ft_isbigger(first, mid) && ft_isbigger(first, last))
		do_op(stacks, RA);
	else if (ft_isbigger(mid, first) && ft_isbigger(mid, last))
		do_op(stacks, RRA);
	if (ft_isbigger(stacks->a->first, stacks->a->first->next))
		do_op(stacks, SA);
	if (ft_isbigger(stacks->a->first, stacks->a->last))
		do_op(stacks, RRA);
}

void	ft_pushsmallest(t_stacks *stacks, int n_op)
{
	int	rot;

	rot = 1;
	if (n_op < 0)
	{
		rot = -1;
		n_op = -n_op;
	}
	while (n_op--)
	{
		if (rot > 0)
			do_op(stacks, RA);
		else
			do_op(stacks, RRA);
	}
	do_op(stacks, PB);
}

void	ft_solve5(t_stacks *stacks)
{
	int	i;
	int	*it;

	if (stacks->a->length == 3)
		ft_solve3(stacks);
	if (ft_dlisordered(stacks->a, ft_isbigger))
		return ;
	i = 0;
	it = ft_dltoit(stacks->a);
	ft_quicksort(it, stacks->a->length);
	while (stacks->a->length > 3)
		ft_pushsmallest(stacks, ft_getclosest(stacks->a, it + i++, 1));
	free(it);
	ft_solve3(stacks);
	do_op(stacks, PA);
	if (stacks->b->length)
		do_op(stacks, PA);
	if (ft_isbigger(stacks->a->first, stacks->a->first->next))
		do_op(stacks, SA);
}

void	ft_solve(t_stacks *stacks)
{
	if (ft_dlisordered(stacks->a, ft_isbigger))
		return ;
	if (stacks->a->length == 2)
		ft_solve2(stacks);
	else if (stacks->a->length == 3)
		ft_solve3(stacks);
	else if (stacks->a->length < 6)
		ft_solve5(stacks);
	else
		ft_solvebig(stacks);
}
