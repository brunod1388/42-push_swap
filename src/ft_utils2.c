/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:54:56 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/05 02:51:57 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_iscommand(char *s)
{
	if (!ft_strcmp(s, SA))
		return (1);
	if (!ft_strcmp(s, SB))
		return (1);
	if (!ft_strcmp(s, PA))
		return (1);
	if (!ft_strcmp(s, PB))
		return (1);
	if (!ft_strcmp(s, RA))
		return (1);
	if (!ft_strcmp(s, RB))
		return (1);
	if (!ft_strcmp(s, RRA))
		return (1);
	if (!ft_strcmp(s, RRB))
		return (1);
	return (0);
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
		if (!ft_isnumber(argv[i]))
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
			*pi = ft_atoi(s + i);
			if (!pi)
				break ;
			ft_dladdlast(dl, pi);
			i += ft_isnumber(s + i);
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
		if (!pi)
		{
			ft_dlclear(&dl);
			return (NULL);
		}
		*pi = ft_atoi(argv[i]);
		ft_dladdlast(dl, pi);
	}
	return (dl);
}
