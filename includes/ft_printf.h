/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:33:36 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/06 01:52:21 by bgoncalv         ###   ########.fr       */
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
	char	*flags;
	int		plus;
	int		minus;
	int		space;
	int		hash;
	int		width;
	int		precision;
	char	type;
	int		blen;
	char	*current;
	char	*buf;
}			t_fdata;

int		ft_printf(const char *format, ...);

t_fdata	ft_readdata(const char *format);

void 	ft_printformat(const char *format, t_fdata *fdata);

int	ft_string_process(t_fdata *fdata);

#endif