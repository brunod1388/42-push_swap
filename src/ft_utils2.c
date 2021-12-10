/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:14:16 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/10 03:38:23 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_clearstack(t_stacks **stack)
{
	ft_dlclear(&(*stack)->a);
	ft_dlclear(&(*stack)->b);
	ft_dlclear(&(*stack)->solution);
	free(*stack);
	*stack = NULL;
}

void	ft_delnode(t_node *node)
{
	char	*s;

	s = node->prev->content;
	s[ft_strlen(s) - 1] = 'r';
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node->content);
	free(node);
}
