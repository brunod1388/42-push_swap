/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:33:36 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/08 16:56:23 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_process_format(t_fdata *fdata)
{
	if (fdata->type == 'c')
		return (ft_char_process(fdata));
	else if (fdata->type == 's')
		return (ft_string_process(fdata));
	else if (fdata->type == 'p')
		return (ft_ulong_process(fdata));
	else if (fdata->type == 'd' || fdata->type == 'i')
		return (ft_int_process(fdata));
	else if (fdata->type == 'u')
		return (ft_uint_process(fdata));
	else if (fdata->type == 'x' || fdata->type == 'X')
		return (ft_hex_process(fdata));
	else if (fdata->type == '%')
		return (ft_percent_process(fdata));
	return (-1);
}

int ft_formatlen_noarg(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s++ == '%')
		{
			while (!ft_ischarset(*s, FORMAT_LIST))
				s++;
			s++;
			continue;
		}
		i++;
	}
	return (i);
}

int	ft_printf_format(char *format, t_fdata *fdata)
{
	int		i;
	
	fdata->blen = ft_formatlen_noarg(format);
	fdata->buf = ft_calloc(fdata->blen, sizeof(char));
	i = 0;
	while (*format)
	{	
		if (*format == '%')
		{
			format = ft_eval_flags(format, fdata);
			if (ft_process_format(fdata) == -1)
				return (-1);
			i += fdata->clen;
		}
		else
			fdata->buf[i++] = *format++;
	}
	fdata->buf[i] = 0;
	ft_putstr(fdata->buf);
	return (fdata->blen);
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
	free(fdata->buf);
	free(fdata);
	return (len);
}
