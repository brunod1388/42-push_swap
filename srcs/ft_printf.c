/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:33:36 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/03 00:50:20 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_analyse_format(char *format)
{
	int nb_arg;

	nb_arg = 0;
	while (*format)
	{
		if (*format == '%')
			nb_arg++;
		format++;
	}
	return (nb_arg);
}

static int	ft_printf_format(char *format, t_fdata *fdata)
{
	int		len;
	int		narg;
	(void)	fdata;
	char	*s;

	len = 0;
	narg = ft_analyse_format(format);
	while (*format)
	{	
		if (*format == '%')
		{
			s = va_arg(fdata->ap, char *);
			len += ft_strlen(s);
			ft_putstr(s);
		}
		else
		{
			ft_putchar(*format);
			len++;
		}
		format++;
	}

	return (len);
}

int ft_printf(const char *format, ...)
{
	int		len;
	t_fdata	*fdata;

	if (!format)
		return (0);
	fdata = malloc(sizeof(t_fdata));
	if (!fdata)
		return (-1);
	va_start(fdata->ap, format);
	len = ft_printf_format((char *) format, fdata);
	va_end(fdata->ap);
	free(fdata);
	return (len);
}
