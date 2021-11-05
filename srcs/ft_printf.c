/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:33:36 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/05 01:05:25 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// static int	ft_get_narg(char *format)
// {
// 	int nb_arg;

// 	nb_arg = 0;
// 	while (*format)
// 	{
// 		if (*format == '%' && format[1] != '%')
// 			nb_arg++;
// 		format++;
// 	}
// 	return (nb_arg);
// }

int	ft_addarg(t_fdata *fdata)
{
	int	len_arg;

	len_arg = ft_strlen(fdata->current);
	fdata->blen += len_arg;
	fdata->buf = ft_realloc(fdata->buf, fdata->blen);
	if (fdata->buf == NULL)
		return (-1);
	ft_strcat(fdata->buf, fdata->current);	
	free(fdata->current);
	return (len_arg);
}

int	ft_int_process(t_fdata *fdata)
{
	int	i;

	i = va_arg(fdata->ap, int);
	fdata->current = ft_itoa(i);
	if (fdata->current == NULL)
		return (-1);
	return (ft_addarg(fdata));
}

int	ft_minhex_process(t_fdata *fdata)
{
	int	i;

	i = va_arg(fdata->ap, int);
	fdata->current = ft_itoa_base(i, "0123456789abcdef");
	if (fdata->current == NULL)
		return (-1);
	return (ft_addarg(fdata));
}

int	ft_caphex_process(t_fdata *fdata)
{
	int	i;

	i = va_arg(fdata->ap, int);
	fdata->current = ft_itoa_base(i, "0123456789ABCDEF");
	if (fdata->current == NULL)
		return (-1);
	return (ft_addarg(fdata));
}

int	ft_char_process(t_fdata *fdata)
{
	char	c;

	c = va_arg(fdata->ap, int);
	fdata->current = malloc(2);
	if (fdata->current == NULL)
		return (-1);
	fdata->current[0] = c;
	fdata->current[1] = 0;
	return (ft_addarg(fdata));
}

int	ft_percent_process(t_fdata *fdata)
{
	fdata->current = malloc(2);
	if (fdata->current == NULL)
		return (-1);
	fdata->current[0] = '%';
	fdata->current[1] = 0;
	return (ft_addarg(fdata));
}

int	ft_string_process(t_fdata *fdata)
{
	fdata->current = ft_strdup(va_arg(fdata->ap, char *));
	return (ft_addarg(fdata));
}

static int ft_eval_format(char *format, t_fdata *fdata)
{	
	int	i;

	i = 1;
	while (!ft_ischarset(format[i], FORMAT_LIST))
		i++;
	fdata->type = format[i];
	return (++i);
}

static int	ft_process_format(t_fdata *fdata)
{
	if (fdata->type == 'c')
		return (ft_char_process(fdata));
	else if (fdata->type == 's')
		return (ft_string_process(fdata));
	else if (fdata->type == 'p')
		return (0);
	else if (fdata->type == 'd')
		return (ft_int_process(fdata));
	else if (fdata->type == 'i')
		return (ft_int_process(fdata));
	else if (fdata->type == 'u')
		return (0);
	else if (fdata->type == 'x')
		return (ft_minhex_process(fdata));
	else if (fdata->type == 'X')
		return (ft_caphex_process(fdata));
	else if (fdata->type == '%')
		return (ft_percent_process(fdata));
	return (-1);
}

static int ft_formatlen_noarg(char *s)
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

static int	ft_printf_format(char *format, t_fdata *fdata)
{	
	int		i;
	int		flen;
	int		arglen;
	
	fdata->blen = ft_formatlen_noarg(format);
	fdata->buf = ft_calloc(fdata->blen, sizeof(char));
	i = 0;
	while (*format)
	{	
		if (*format == '%')
		{
			flen = ft_eval_format(format, fdata);
			arglen = ft_process_format(fdata);
			if (flen == -1 || arglen == -1)
				return (-1);
			i += arglen;
			format += flen;
		}
		else
			fdata->buf[i++] = *format++;
	}
	fdata->buf[i] = 0;
	ft_putstr(fdata->buf);
	return (fdata->blen);
}

//gerer erreur -1
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
