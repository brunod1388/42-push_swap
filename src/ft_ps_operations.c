/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:28:34 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/22 00:37:42 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	elswap(t_dlist *dl)
{
	void	*tmp;

	tmp = dl->first->content;
	dl->first->content = dl->first->next->content;
	dl->first->next->content = tmp;
}

void	elpush(t_dlist *a, t_dlist *b)
{
	ft_dladdfirst(a, ft_dlpushfirst(b));
}

void	elrotate(t_dlist *dl)
{
	ft_dlputlast(dl, ft_dlpushfirst(dl));
}

void	elreverse(t_dlist *dl)
{
	ft_dlputfirst(dl, ft_dlpushlast(dl));
}

void	do_op(t_dlist *a, t_dlist *b, char *op)
{
	if (op[0] == 's')
	{
		if (op[1] == 'a' || op[1] == 's')
			elswap(a);
		if (op[1] == 'b' || op[1] == 's')
			elswap(b);
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
