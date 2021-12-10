/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:14:16 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/10 01:28:22 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	*ft_intup(void *n)
{
	int	*i;

	i = malloc(sizeof(int));
	if (!i)
		return (NULL);
	*i = *(int *)n;
	return (i);
}

void	*ft_strup(void *s)
{
	return (ft_strdup(s));
}

t_stacks	*ft_stackscpy(t_stacks *stacks)
{
	t_stacks	*dst;

	dst = malloc(sizeof(t_stacks));
	if (!dst)
		return (NULL);
	dst->a = ft_dlcpy(stacks->a, ft_intup);
	dst->b = ft_dlcpy(stacks->b, ft_intup);
	dst->solution = ft_dlcpy(stacks->solution, ft_strup);
	if (!dst->a || !dst->b || !dst->solution)
		ft_clearstack(&dst);
	return (dst);
}

void	ft_opti_rot(t_stacks *stacks)
{
	t_node	*node;
	t_node	*tmp;
	char	*current;
	char	*prev;

	node = stacks->solution->first->next;
	while (node)
	{
		current = node->content;
		prev = node->prev->content;
		tmp = node->next;
		if ((!ft_strcmp(current, RA) && !ft_strcmp(prev, RB))
			|| (!ft_strcmp(current, RB) && !ft_strcmp(prev, RA)))
		{
			ft_delnode(node);
			stacks->solution->length--;
		}
		else if ((!ft_strcmp(current, RRA) && !ft_strcmp(prev, RRB))
			|| (!ft_strcmp(current, RRB) && !ft_strcmp(prev, RRA)))
		{
			ft_delnode(node);
			stacks->solution->length--;
		}
		node = tmp;
	}
}

void	ft_bigopti(t_stacks *stacks)
{
	t_stacks	*copy;
	t_stacks	*min;
	int			i;
	int			imin;

	i = 1;
	imin = 1;
	min = ft_stackscpy(stacks);
	ft_solvebig(min, i);
	while (++i < 25)
	{
		copy = ft_stackscpy(stacks);
		ft_solvebig(copy, i);
		if (min->solution->length > copy->solution->length)
		{
			ft_clearstack(&min);
			min = copy;
			imin = i;
		}
		else
			ft_clearstack(&copy);
	}
	ft_clearstack(&min);
	ft_solvebig(stacks, imin);
}
