/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:03:49 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/24 22:50:40 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_solve2(t_dlist *a, t_dlist *b)
{
	if (a->first->content > a->first->next->content)
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
}

void	ft_solve5(t_dlist *a, t_dlist *b)
{
	if (ft_dlisordered(a, ft_isbigger))
		return ;
	do_op(a, b, PA);
	do_op(a, b, PA);
	ft_printf("%s\n%s\n", PA, PA);
	ft_solve3(a, b);
	while (b->length)
	{
		if (ft_isbigger())
	}
}

void	ft_solve(t_dlist *a, t_dlist *b)
{
	if (a->length == 2)
		ft_solve2(a, b);
	if (a->length == 3)
		ft_solve3(a, b);
	else
		ft_solvebig(a, b);
}
