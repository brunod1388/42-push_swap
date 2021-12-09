/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:54:56 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/08 02:29:09 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_isdlok(t_dlist *dl)
{
	t_node	*node;
	t_node	*current;
	int		i;

	node = dl->first;
	while (node->next)
	{
		current = node;
		while (current->next)
		{
			current = current->next;
			i = *(int *) current->content;
			if (i == *(int *) node->content)
				return (0);
		}
		node = node->next;
	}
	return (1);
}

int	*ft_dltoit(t_dlist *dl)
{
	t_node	*current;
	int		*i_tab;
	int		i;

	if (!dl || dl->length == 0)
		return (NULL);
	i_tab = malloc(sizeof(int) * dl->length);
	if (!i_tab)
		return (NULL);
	current = dl->first;
	i = 0;
	while (current)
	{
		i_tab[i++] = *(int *)current->content;
		current = current->next;
	}
	return (i_tab);
}

static int	ft_isarok(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (ft_isnumber(argv[i]) < 1)
			return (0);
	return (1);
}

t_dlist	*ft_sttodl(char *s)
{
	t_dlist	*dl;
	int		*pi;
	int		i;

	dl = ft_dlnew();
	i = 0;
	while (s[i])
	{
		if (ft_isnumber(s + i))
		{
			pi = malloc(sizeof(int));
			if (!pi)
				break ;
			*pi = ft_atoi(s + i);
			ft_dladdlast(dl, pi);
			i += ft_abs(ft_isnumber(s + i));
		}
		else if (s[i] == ' ')
			i++;
		else
			break ;
	}
	if (!pi || s[i])
		ft_dlclear(&dl);
	return (dl);
}

t_dlist	*ft_atodl(int argc, char **argv)
{
	t_dlist	*dl;
	int		*pi;
	int		i;

	if (!ft_isarok(argc, argv))
		return (NULL);
	if (argc == 2)
		return (ft_sttodl(argv[1]));
	dl = ft_dlnew();
	i = 0;
	while (++i < argc)
	{
		pi = malloc(sizeof(int));
		if (!pi || ft_atol(argv[i]) < INT_MIN || INT_MAX < ft_atol(argv[i]))
		{
			if (pi)
				free(pi);
			ft_dlclear(&dl);
			return (NULL);
		}
		*pi = ft_atoi(argv[i]);
		ft_dladdlast(dl, pi);
	}
	return (dl);
}
