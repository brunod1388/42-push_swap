/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:29:44 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/20 00:34:06 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	print_stacks(t_list *a, t_list *b)
{
	int		sizea;
	int		sizeb;
	char	*acontent;
	char	*bcontent;
	int		i;

	sizea = ft_lstsize(a);
	sizeb = ft_lstsize(b);
	i = 0;
	while (i < sizea || i < sizeb)
	{
		acontent = ft_getnblist(a, i);
		bcontent = ft_getnblist(b, i);
		if (acontent && bcontent)
			ft_printf("%s %s\n", acontent, bcontent);
		if (acontent && !bcontent)
			ft_printf("%s %s\n", acontent, "");
		if (!acontent && bcontent)
			ft_printf("%s %s\n", " ", bcontent);
		i++;
	}
	ft_printf("_ _\n");
	ft_printf("a b\n");
}
