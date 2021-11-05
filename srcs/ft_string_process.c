/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:21:29 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/03 19:51:44 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string_process(t_fdata *fdata)
{
	char	*s;
	int		len_arg;

	s = va_arg(format->ap, char *);
	len_arg = ft_strlen(s)
	format->blen += len_arg;
	ft_realloc(format->buf, format->blen);
	ft_strcat(format->buf, s);
	return (len_arg);
}

