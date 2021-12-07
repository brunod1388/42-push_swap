/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:41:56 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/07 16:13:31 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isnumber(char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[0] == '-' && ft_isdigit(s[1]))
		s++;
	while (ft_isdigit(s[i]))
		i++;
	if (!ft_isdigit(s[i]))
		return (-i);
	return (i);
}
