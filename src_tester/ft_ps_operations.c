/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:28:34 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/04 03:32:20 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static int	g_counter;

void	set_counter(int i)
{
	g_counter = i;
}

int	get_counter(void)
{
	return (g_counter);
}

static void	swap(t_dlist *dl)
{
	void	*tmp;

	if (dl->length < 2)
		return ;
	tmp = dl->first->content;
	dl->first->content = dl->first->next->content;
	dl->first->next->content = tmp;
}

void	do_nbop(t_dlist *a, t_dlist *b, int n, char *op)
{
	int	i;

	i = -1;
	while (++i < n)
		do_op(a, b, op);
}

void	do_op(t_dlist *a, t_dlist *b, char *op)
{
	if (!ft_strcmp(op, SA) || !ft_strcmp(op, SS))
		swap(a);
	if (!ft_strcmp(op, SB) || !ft_strcmp(op, SS))
		swap(b);
	if (!ft_strcmp(op, PA))
		ft_dlputfirst(a, ft_dlpushfirst(b));
	if (!ft_strcmp(op, PB))
		ft_dlputfirst(b, ft_dlpushfirst(a));
	if (!ft_strcmp(op, RA) || !ft_strcmp(op, RR))
		ft_dlputlast(a, ft_dlpushfirst(a));
	if (!ft_strcmp(op, RB) || !ft_strcmp(op, RR))
		ft_dlputlast(b, ft_dlpushfirst(b));
	if (!ft_strcmp(op, RRA) || !ft_strcmp(op, RRR))
		ft_dlputfirst(a, ft_dlpushlast(a));
	if (!ft_strcmp(op, RRB) || !ft_strcmp(op, RRR))
		ft_dlputfirst(b, ft_dlpushlast(b));
	g_counter++;
}
