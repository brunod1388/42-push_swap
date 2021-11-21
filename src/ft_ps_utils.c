/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:29:44 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/22 00:55:19 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

// int	ft_isbigger(void *a, void *b)
// {
// 	return (*(int *)a > *(int *)b);
// }

static int	getilen(int x)
{
	if (x <= -100000000 || x >= 1000000000)
		return 10;
	if (x <= -10000000 || x >= 100000000)
		return 9;
	if (x <= -1000000 || x >= 10000000)
		return 8;
	if (x <= -100000 || x >= 1000000)
		return 7;
	if (x <= -10000 || x >= 100000)
		return 6;
	if (x <= -1000 || x >= 10000)
		return 5;
	if (x <= -100 || x >= 1000)
		return 4;
	if (x <= -10 || x >= 100)
		return 3;
	if (x <= -1 || x >= 10)
		return 2;
	return 1;
}

static int	get_maxlcontent(t_dlist *a)
{
	t_node 	*current;
	int		maxl;
	int		l;

	maxl = 0;
	l = 0;
	current = a->first;
	while (current)
	{
		l = getilen(*(int *)current->content);
		if (l > maxl)
			maxl = l;
		current = current->next;
	}
	return (maxl);
}

static void	ft_printformatnode(t_node *a, int l, char c)
{
	char	*s;
	int		i;

	s = ft_itoa(*(int *)a->content);
	i = l - (int) ft_strlen(s);
	while (i--)
		ft_putchar(c);
	ft_putstr(s);
}

void	print_stacks(t_dlist *a, t_dlist *b)
{
	size_t	i;
	int		nchara;
	int		ncharb;
	t_node	*currenta;
	t_node	*currentb;

	nchara = get_maxlcontent(a);
	ncharb = get_maxlcontent(b);
	if (a->length > b->length)
		i = a->length;
	if (a->length < b->length)
		i = b->length;
	ft_printf("TSAMERRRRREE\n");
	currenta = a->first;
	currentb = b->first;
	while (i--)
	{
		if (i > a->length)
			ft_printformatnode(currenta, nchara, ' ');
		else
			ft_printformatnode(NULL, nchara, ' ');
		ft_putchar(' ');
		if (i > b->length)
			ft_printformatnode(currentb, ncharb, ' ');
		else
			ft_printformatnode(NULL, ncharb, ' ');
		ft_putchar('\n');
	}
	ft_printf("_ _\n");
	ft_printf("a b\n");
}
