/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_solve_big2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:39:44 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/05 04:21:35 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_ischunk(int n, int *i_tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		if (n == i_tab[i++])
			return (1);
	return (0);
}

int	ft_getclosest(t_dlist *a, int *i_tab, int size)
{
	t_node	*current;
	int		nbrot;
	int		nbrrot;

	nbrot = 0;
	current = a->first;
	while (current)
	{
		if (ft_ischunk(*(int *)current->content, i_tab, size))
			break ;
		current = current->next;
		nbrot++;
	}
	nbrrot = 1;
	current = a->last;
	while (current)
	{
		if (ft_ischunk(*(int *)current->content, i_tab, size))
			break ;
		current = current->prev;
		nbrrot++;
	}
	if (nbrot > nbrrot)
		return (-nbrrot);
	return (nbrot);
}

void	ft_setchunk(t_dlist *a, t_dlist *b, int *i_tab, int size)
{
	int	chunk_nb;
	int	chunk_size;
	int	current_chunk;
	int	nb_count;
	int	op;

	chunk_nb = 1 + ft_sqrt(size) / 2;
	current_chunk = -1;
	chunk_size = size / chunk_nb + 1;
	while (++current_chunk < chunk_nb)
	{
		nb_count = -1;
		if (current_chunk == size % chunk_nb)
			chunk_size--;
		while (++nb_count < chunk_size)
		{
			op = ft_getclosest(a, i_tab, chunk_size);
			if (op > 0)
				do_nbop(a, b, op, RA);
			else if (op < 0)
				do_nbop(a, b, -op, RRA);
			do_op(a, b, PB);
		}
		i_tab += chunk_size;
	}
}

int	ft_ontheway(t_dlist *a, t_dlist *b, int nb_op, int n)
{
	char	*op;
	int		to_swap;

	if (nb_op < 0)
		op = ft_strdup(RRB);
	else
		op = ft_strdup(RB);
	if (nb_op < 0)
		nb_op = -nb_op;
	to_swap = 0;
	while (nb_op--)
	{
		if (!to_swap && *(int *) b->first->content == n)
		{
			do_op(a, b, PA);
			if (op[1] == 'r')
				do_op (a, b, op);
			to_swap = 1;
		}
		else
			do_op (a, b, op);
	}
	free(op);
	return (to_swap);
}

void	ft_solvebig(t_dlist *a, t_dlist *b)
{
	int	*it;
	int	nb_op;
	int	to_swap;

	it = ft_dltoit(a);
	ft_quicksort(it, a->length);
	ft_setchunk(a, b, it, a->length);
	while (b->length)
	{
		to_swap = 0;
		nb_op = ft_getclosest(b, it + b->length - 1, 1);
		if (b->length > 1)
			to_swap = ft_ontheway(a, b, nb_op, it[b->length - 2]);
		else
		{
			if (nb_op > 0)
				do_nbop(a, b, nb_op, RB);
			else if (nb_op < 0)
				do_nbop(a, b, -nb_op, RRB);
		}
		do_op(a, b, PA);
		if (to_swap)
			do_op(a, b, SA);
	}
	free(it);
}
