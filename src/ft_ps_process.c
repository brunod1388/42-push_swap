/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:33:07 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/24 17:17:30 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

size_t	ft_dl_getmaxi(t_dlist *dl, size_t l)
{
	size_t	i;
	size_t	imax;
	int		max;
	t_node	*current;

	current = dl->first;
	i = 1;
	imax = 0;
	max = *(int *) current->content;
	while (i < l)
	{
		current = current->next;
		if (*(int *) current->content > max)
		{
			max = *(int *) current->content;
			imax = i;
		}
		i++;
	}
	return (imax);
}

size_t	ft_dl_getmini(t_dlist *dl, size_t l)
{
	size_t	i;
	size_t	imin;
	int		min;
	t_node	*current;

	current = dl->first;
	i = 1;
	imin = 0;
	min = *(int *) current->content;
	while (i < l)
	{
		current = current->next;
		if (*(int *) current->content < min)
		{
			min = *(int *) current->content;
			imin = i;
		}
		i++;
	}
	return (imin);
}

int	ft_isbigger(t_node *a, t_node *b)
{
	return (*(int *)a->content > *(int *)b->content);
}

int	ft_issmaller(t_node *a, t_node *b)
{
	return (*(int *)a->content < *(int *)b->content);
}
