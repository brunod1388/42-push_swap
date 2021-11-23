/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:28:34 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/23 21:46:00 by bgoncalv         ###   ########.fr       */
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

static void	push(t_dlist *a, t_dlist *b)
{
	ft_dlputfirst(a, ft_dlpushfirst(b));
}

static void	rotate(t_dlist *dl)
{
	ft_dlputlast(dl, ft_dlpushfirst(dl));
}

static void	reverse(t_dlist *dl)
{
	ft_dlputfirst(dl, ft_dlpushlast(dl));
}

void	do_op(t_dlist *a, t_dlist *b, char *op)
{
	if (!ft_strcmp(op, SA) || !ft_strcmp(op, SS))
		swap(a);
	if (!ft_strcmp(op, SB) || !ft_strcmp(op, SS))
		swap(b);
	if (!ft_strcmp(op, PA))
		push(b, a);
	if (!ft_strcmp(op, PB))
		push(a, b);
	if (!ft_strcmp(op, RA) || !ft_strcmp(op, RR))
		rotate(a);
	if (!ft_strcmp(op, RB) || !ft_strcmp(op, RR))
		rotate(b);
	if (!ft_strcmp(op, RRA) || !ft_strcmp(op, RRR))
		reverse(a);
	if (!ft_strcmp(op, RRB) || !ft_strcmp(op, RRR))
		reverse(b);
}
