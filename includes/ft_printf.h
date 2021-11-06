/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:33:36 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/07 00:18:24 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>
# define FORMAT_LIST "cspdiuxX%"
# define FLAGS_LIST "-# +"

#include <stdio.h>

typedef struct	s_fdata
{
	va_list	ap;
	int		plus;
	int		minus;
	int		space;
	int		hash;
	int		width;
	int		precision;
	char	type;
	int		clen;	//remplacer strlen(current)
	int		blen;
	char	*current;
	char	*buf;
}			t_fdata;

int		ft_printf(const char *format, ...);

void	ft_printformat(const char *format, t_fdata *fdata);

#endif