/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:28:34 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/20 00:32:36 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	elswap(t_list *l)
{
	void	*tmp;

	tmp = l->next->content;
	l->next->content = l->content;
	l->content = tmp;
}

void	elpush(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = (*b)->next;
	(*b)->next = NULL;
	ft_lstadd_front(a,*b);
	*b = tmp;
}

void	elrotate(t_list **l)
{
	t_list	*tmp;

	if (!*l || !(*l)->next)
		return ;
	tmp = (*l)->next;
	(*l)->next = NULL;
	ft_lstadd_back(&tmp, *l);
	*l = tmp;
}

void	elreverse(t_list **l)
{
	t_list	*prelast;

	if (!*l || !(*l)->next)
		return ;
	prelast = ft_lstprelast(*l);
	ft_lstadd_front(l, prelast->next);
	prelast->next = NULL;
}

void	do_op(t_list **a, t_list **b, char *op)
{
	if (op[0] == 's')
	{
		if (op[1] == 'a' || op[1] == 's')
			elswap(*a);
		if (op[1] == 'b' || op[1] == 's')
			elswap(*b);
	}
	else if (op[0] == 'p' && op[1] == 'b')
		elpush(b, a);
	else if (op[0] == 'p' && op[1] == 'a')
		elpush(a, b);
	else if (ft_strlen(op) == 2 && op[0] == 'r')
	{
		if (op[1] == 'a' || op[1] == 'r')
			elrotate(a);
		if (op[1] == 'a' || op[1] == 'r')
			elrotate(b);
	}
	else if (ft_strlen(op) == 3 && op[0] == 'r' && op[1] == 'r')
	{
		if (op[2] == 'a' || op[2] == 'r')
			elreverse(a);
		if (op[2] == 'a' || op[2] == 'r')
			elreverse(b);
	}
}
