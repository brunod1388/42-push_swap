/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:28:34 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/10 00:46:58 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	swap(t_dlist *dl)
{
	void	*tmp;

	if (dl->length < 2)
		return ;
	tmp = dl->first->content;
	dl->first->content = dl->first->next->content;
	dl->first->next->content = tmp;
}

void	do_nbop(t_stacks *stacks, int n, char *op)
{
	int	i;

	i = -1;
	while (++i < n)
		do_op(stacks, op);
}

void	do_op(t_stacks *stacks, char *op)
{
	if (!ft_strcmp(op, SA) || !ft_strcmp(op, SS))
		swap(stacks->a);
	else if (!ft_strcmp(op, SB) || !ft_strcmp(op, SS))
		swap(stacks->b);
	else if (!ft_strcmp(op, PA))
		ft_dlputfirst(stacks->a, ft_dlpushfirst(stacks->b));
	else if (!ft_strcmp(op, PB))
		ft_dlputfirst(stacks->b, ft_dlpushfirst(stacks->a));
	else if (!ft_strcmp(op, RA) || !ft_strcmp(op, RR))
		ft_dlputlast(stacks->a, ft_dlpushfirst(stacks->a));
	else if (!ft_strcmp(op, RB) || !ft_strcmp(op, RR))
		ft_dlputlast(stacks->b, ft_dlpushfirst(stacks->b));
	else if (!ft_strcmp(op, RRA) || !ft_strcmp(op, RRR))
		ft_dlputfirst(stacks->a, ft_dlpushlast(stacks->a));
	else if (!ft_strcmp(op, RRB) || !ft_strcmp(op, RRR))
		ft_dlputfirst(stacks->b, ft_dlpushlast(stacks->b));
	ft_dladdlast(stacks->solution, ft_strdup(op));
}
