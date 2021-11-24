/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_solve_big.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:39:44 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/24 22:53:19 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

// void	ft_push_subpart(t_dlist *a, t_dlist *b, int *i_tab)
// {

// }

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

	chunk_nb = ft_sqrt(size) / 2;
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

void	ft_solvebig(t_dlist *a, t_dlist *b)
{
	int	*it;
	int	op;

	it = ft_dltoit(a);
	ft_quicksort(it, a->length);
	ft_setchunk(a, b, it, a->length);
	while (b->length)
	{
		op = ft_getclosest(b, it + b->length - 1, 1);
		if (op > 0)
			do_nbop(a, b, op, RB);
		else if (op < 0)
			do_nbop(a, b, -op, RRB);
		do_op(a, b, PA);
	}
	free(it);
}
