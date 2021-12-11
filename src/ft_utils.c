/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:33:07 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/11 04:04:29 by bgoncalv         ###   ########.fr       */
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

void	ft_pushclosest(t_stacks *stacks, int op, int a_to_b)
{
	if (a_to_b)
	{
		if (op > 0)
			do_nbop(stacks, op, RA);
		else if (op < 0)
			do_nbop(stacks, -op, RRA);
		do_op(stacks, PB);
	}
	else
	{
		if (op > 0)
			do_nbop(stacks, op, RB);
		else if (op < 0)
			do_nbop(stacks, -op, RRB);
		do_op(stacks, PA);
	}
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

int	ft_isbigger(t_node *a, t_node *b)
{
	return (*(int *)a->content > *(int *)b->content);
}

void	ft_printsol(t_stacks *stacks)
{
	t_node	*current;

	current = stacks->solution->first;
	while (current)
	{
		ft_putstr(current->content);
		ft_putstr("\n");
		current = current->next;
	}
}
