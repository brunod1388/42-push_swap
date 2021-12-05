/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:03:49 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/05 02:05:24 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_solve2(t_dlist *a, t_dlist *b)
{
	if (ft_isbigger(a->first, a->last))
		do_op(a, b, SA);
}

void	ft_solve3(t_dlist *a, t_dlist *b)
{
	t_node	*first;
	t_node	*mid;
	t_node	*last;

	first = a->first;
	mid = a->first->next;
	last = a->last;
	if (ft_isbigger(first, mid) && ft_isbigger(first, last))
		do_op(a, b, RA);
	else if (ft_isbigger(mid, first) && ft_isbigger(mid, last))
		do_op(a, b, RRA);
	if (ft_isbigger(a->first, a->first->next))
		do_op(a, b, SA);
	if (ft_isbigger(a->first, a->last))
		do_op(a, b, RRA);
}

void	ft_pushsm(t_dlist *a, t_dlist *b, int n_op)
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
			do_op(a, b, RA);
		else
			do_op(a, b, RRA);
	}
	do_op(a, b, PB);
}

void	ft_solve5(t_dlist *a, t_dlist *b)
{
	int	i;
	int	*it;

	if (a->length == 3)
		ft_solve3(a, b);
	if (ft_dlisordered(a, ft_isbigger))
		return ;
	i = 0;
	it = ft_dltoit(a);
	ft_quicksort(it, a->length);
	while (a->length > 3)
		ft_pushsm(a, b, ft_getclosest(a, it + i++, 1));
	free(it);
	ft_solve3(a, b);
	do_op(a, b, PA);
	if (b->length)
		do_op(a, b, PA);
	if (ft_isbigger(a->first, a->first->next))
		do_op(a, b, SA);
}

void	ft_solve(t_dlist *a, t_dlist *b)
{
	if (a->length == 2)
		ft_solve2(a, b);
	else if (a->length == 3)
		ft_solve3(a, b);
	else if (a->length < 6)
		ft_solve5(a, b);
	else
		ft_solvebig(a, b);
}
