/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:29:44 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/09 15:27:10 by bgoncalv         ###   ########.fr       */
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

static void	print_stackline(t_stacks *stacks, t_node **current, int l)
{
	size_t	i;

	i = stacks->b->length;
	if (stacks->a->length > stacks->b->length)
		i = stacks->a->length;
	while (i)
	{
		if (i <= stacks->a->length)
		{
			ft_printformatnode(current[0], l, ' ');
			current[0] = current[0]->next;
		}
		else
			ft_printformatnode(NULL, l, ' ');
		ft_putchar(' ');
		if (i <= stacks->b->length)
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

void	print_stacks(t_stacks *stacks)
{
	int		l;
	int		lb;
	t_node	*current[2];

	l = get_maxlcontent(stacks->a);
	lb = get_maxlcontent(stacks->b);
	if (lb > l)
		l = lb;
	if (!l)
		l++;
	current[0] = stacks->a->first;
	current[1] = stacks->b->first;
	print_stackline(stacks, current, l);
	ft_printformatnode(NULL, l, '-');
	ft_printf(" ");
	ft_printformatnode(NULL, l, '-');
	ft_putchar('\n');
	ft_printformatnode(NULL, l - 1, ' ');
	ft_printf("a b\n");
}
