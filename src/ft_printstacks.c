/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:29:44 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/28 03:16:46 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static int	getilen(int x)
{
	if (x <= -100000000 || x >= 1000000000)
		return (10);
	if (x <= -10000000 || x >= 100000000)
		return (9);
	if (x <= -1000000 || x >= 10000000)
		return (8);
	if (x <= -100000 || x >= 1000000)
		return (7);
	if (x <= -10000 || x >= 100000)
		return (6);
	if (x <= -1000 || x >= 10000)
		return (5);
	if (x <= -100 || x >= 1000)
		return (4);
	if (x <= -10 || x >= 100)
		return (3);
	if (x <= -1 || x >= 10)
		return (2);
	return (1);
}

static int	get_maxlcontent(t_dlist *a)
{
	t_node	*current;
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

	if (a)
		s = ft_itoa(*(int *)a->content);
	else
		s = ft_strdup("");
	i = l - (int) ft_strlen(s);
	if (i < 0)
		i = 0;
	while (i--)
		ft_putchar(c);
	ft_putstr(s);
	free(s);
}

static void	print_stackline(t_dlist **dl, t_node **current, int l)
{
	size_t	i;

	i = dl[1]->length;
	if (dl[0]->length > dl[1]->length)
		i = dl[0]->length;
	while (i)
	{
		if (i <= dl[0]->length)
		{
			ft_printformatnode(current[0], l, ' ');
			current[0] = current[0]->next;
		}
		else
			ft_printformatnode(NULL, l, ' ');
		ft_putchar(' ');
		if (i <= dl[1]->length)
		{
			ft_printformatnode(current[1], l, ' ');
			current[1] = current[1]->next;
		}
		else
			ft_printformatnode(NULL, l, ' ');
		ft_putchar('\n');
		i--;
	}
}

void	print_stacks(t_dlist *a, t_dlist *b)
{
	int		l;
	int		lb;
	t_node	*current[2];
	t_dlist	*dl_tab[2];

	dl_tab[0] = a;
	dl_tab[1] = b;
	l = get_maxlcontent(a);
	lb = get_maxlcontent(b);
	if (lb > l)
		l = lb;
	if (!l)
		l++;
	current[0] = a->first;
	current[1] = b->first;
	print_stackline(dl_tab, current, l);
	ft_printformatnode(NULL, l, '-');
	ft_printf(" ");
	ft_printformatnode(NULL, l, '-');
	ft_putchar('\n');
	ft_printformatnode(NULL, l - 1, ' ');
	ft_printf("a b\n");
}
