/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:33:36 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/08 00:24:58 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_addprefix(t_fdata *fdata, char fillchar, int nb_fillchar)
{
	char	*dst;
	int		i;

	fdata->clen += nb_fillchar;
	dst = malloc(fdata->clen + 1);
	if (!dst)
		return (-1);
	i = 0;
	while (i < nb_fillchar)
		dst[i++] = fillchar;
	ft_strcpy(&dst[i], fdata->current);
	free(fdata->current);
	fdata->current = dst;
	return (fdata->clen);
}

int	ft_addsufix(t_fdata *fdata, char fillchar, int nb_fillchar)
{
	int		i;

	fdata->current = realloc(fdata->current, fdata->clen + nb_fillchar + 1);
	if (!fdata->current)
		return (-1);
	i = fdata->clen;
	fdata->clen += nb_fillchar;
	while (i < fdata->clen)
		fdata->current[i++] = fillchar;
	fdata->current[i] = 0;
	return (fdata->clen);
}

void print_data(t_fdata *fdata)
{
	printf("plus      : %i\n", fdata->plus);
	printf("minus     : %i\n", fdata->minus);
	printf("space     : %i\n", fdata->space);
	printf("hash      : %i\n", fdata->hash);
	printf("width     : %i\n", fdata->width);
	printf("precision : %i\n", fdata->precision);
	printf("type      : %c\n", fdata->type);
	printf("current   : %s\n", fdata->current);
	printf("clen      : %i\n", fdata->clen);
	printf("buf       : %s\n\n", fdata->buf);
	printf("blen      : %i\n", fdata->blen);
}

int	ft_addarg(t_fdata *fdata)
{
	fdata->blen += fdata->clen;
	fdata->buf = ft_realloc(fdata->buf, fdata->blen + 1);
	if (fdata->buf == NULL)
		return (-1);
	ft_strcat(fdata->buf, fdata->current);	
	free(fdata->current);
	return (fdata->clen);
}

int	ft_width_process(t_fdata *fdata)
{
	if (fdata->width > fdata->clen)
	{
		if (fdata->minus)
		{
			if (ft_addsufix(fdata, ' ', fdata->width - fdata->clen) == -1)
				return (-1);
		}
		else
		{
			if (ft_addprefix(fdata, ' ', fdata->width - fdata->clen) == -1)
				return (-1);
		}
	}
	return (fdata->clen);
}

int	ft_space_process(t_fdata *fdata)
{
	if (fdata->space && fdata->current[0] != ' ' &&
			!ft_memchr(fdata->current, '-', fdata->clen))
		ft_addprefix(fdata, ' ', 1);
	return (fdata->clen);
}

int	ft_hash_process(t_fdata *fdata)
{
	char *dst;

	if (fdata->type == 'p' || 
		(fdata->hash && (fdata->type == 'x' || fdata->type == 'X')))
	{
		dst = malloc(fdata->clen + 3);
		if (!dst)
			return (-1);
		dst[0] = '0';
		if (fdata->type == 'p' || fdata->type == 'x')
			dst[1] = 'x';
		else
			dst[1] = 'X';
		dst[2] = 0;
		ft_strcat(dst, fdata->current);
		free(fdata->current);
		fdata->current = dst;
		fdata->clen = ft_strlen(fdata->current);
	}
	return (fdata->clen);
}

int	ft_plus_process(t_fdata *fdata)
{	
	if (fdata->plus && !ft_memchr(fdata->current, '-', fdata->clen))
	{
		ft_addprefix(fdata, '+', 1);
	}
	return (fdata->clen);
}

int	ft_precision_string_process(t_fdata *fdata)
{
	if (fdata->dot && fdata->precision < fdata->clen)
	{
		fdata->current[fdata->precision] = 0;
		fdata->clen = fdata->precision;
	}
	return (fdata->clen);
}

int	ft_precision_number_process(t_fdata *fdata)
{
	char *neg_sign;

	if (fdata->precision > fdata->clen)
	{
		if (ft_addprefix(fdata, '0', fdata->precision - fdata->clen) == -1)
			return (-1);
		if (fdata->type == 'd' || fdata->type == 'i')
		{
			neg_sign = ft_memchr(fdata->current, '-', fdata->clen);
			if (neg_sign)
			{
				*neg_sign = '0';
				if (ft_addprefix(fdata, '-', 1) == -1)
					return (-1);
			}
		}
	}
	else if (fdata->dot && fdata->precision == 0 &&
		fdata->current[0] == '0' && fdata->current[1] == 0)
	{
			free(fdata->current);
			fdata->current = ft_strdup("");
			fdata->clen = 0;
	}
	return (fdata->clen);
}

int	ft_int_process(t_fdata *fdata)
{
	int	i;

	i = va_arg(fdata->ap, int);
	fdata->current = ft_itoa(i);
	if (fdata->current == NULL)
		return (-1);
	fdata->clen = ft_strlen(fdata->current);
	ft_precision_number_process(fdata);
	ft_plus_process(fdata);
	ft_space_process(fdata);
	ft_width_process(fdata);
	return (ft_addarg(fdata));
}

int	ft_uint_process(t_fdata *fdata)
{
	unsigned int	i;

	i = va_arg(fdata->ap, unsigned int);
	fdata->current = ft_uitoa(i);
	if (fdata->current == NULL)
		return (-1);
	fdata->clen = ft_strlen(fdata->current);
	ft_precision_number_process(fdata);
	ft_plus_process(fdata);
	ft_width_process(fdata);
	return (ft_addarg(fdata));
}

int	ft_ulong_process(t_fdata *fdata)
{
	unsigned long	ul;

	ul = va_arg(fdata->ap, unsigned long);
	fdata->current = ft_ultoa_base(ul, "0123456789abcdef");
	if (fdata->current == NULL)
		return (-1);
	fdata->clen = ft_strlen(fdata->current);
	ft_hash_process(fdata);
	ft_width_process(fdata);
	return (ft_addarg(fdata));
}

int	ft_minhex_process(t_fdata *fdata)
{
	unsigned int	i;

	i = va_arg(fdata->ap, unsigned int);
	fdata->current = ft_uitoa_base(i, "0123456789abcdef");
	if (fdata->current == NULL)
		return (-1);
	fdata->clen = ft_strlen(fdata->current);
	ft_precision_number_process(fdata);
	ft_plus_process(fdata);
	ft_hash_process(fdata);
	ft_width_process(fdata);
	return (ft_addarg(fdata));
}

int	ft_caphex_process(t_fdata *fdata)
{
	unsigned int	i;

	i = va_arg(fdata->ap, unsigned int);
	fdata->current = ft_uitoa_base(i, "0123456789ABCDEF");
	if (fdata->current == NULL)
		return (-1);
	fdata->clen = ft_strlen(fdata->current);
	ft_precision_number_process(fdata);
	ft_plus_process(fdata);
	ft_hash_process(fdata);
	ft_width_process(fdata);
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
	fdata->clen = 1;
	ft_space_process(fdata);
	ft_width_process(fdata);
	return (ft_addarg(fdata));
}

int	ft_percent_process(t_fdata *fdata)
{
	fdata->current = malloc(2);
	if (fdata->current == NULL)
		return (-1);
	fdata->current[0] = '%';
	fdata->current[1] = 0;
	fdata->clen = 1;
	ft_width_process(fdata);
	return (ft_addarg(fdata));
}

int	ft_string_process(t_fdata *fdata)
{
	fdata->current = ft_strdup(va_arg(fdata->ap, char *));
	fdata->clen = ft_strlen(fdata->current);
	ft_precision_string_process(fdata);
	ft_width_process(fdata);
	return (ft_addarg(fdata));
}

void	ft_fdata_init(t_fdata *fdata)
{
	fdata->plus = 0;
	fdata->minus = 0;
	fdata->space = 0;
	fdata->hash = 0;
	fdata->dot = 0;
	fdata->width = 0;
	fdata->precision = 0;
	fdata->clen = 0;
}

static char *ft_eval_format(char *format, t_fdata *fdata)
{
	ft_fdata_init(fdata);
	while (ft_ischarset(*(++format), FLAGS_LIST))
	{
		if (*format == '+')
			fdata->plus = 1;
		if (*format == '#')
			fdata->hash = 1;
		if (*format == '-')
			fdata->minus = 1;
		if (*format == ' ')
			fdata->space = 1;
	}
	if (ft_isdigit(*format) && !fdata->precision)
		fdata->width = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	if (*format == '.')
		fdata->dot = 1;
	if(format[0] == '.' && ft_isdigit(format[1]))
		fdata->precision = ft_atoi(++format);
	while (ft_isdigit(*format))
		format++;
	if (ft_ischarset(*format, FORMAT_LIST))
		fdata->type = *format;
	return (++format);
}

static int	ft_process_format(t_fdata *fdata)
{
	if (fdata->type == 'c')
		return (ft_char_process(fdata));
	else if (fdata->type == 's')
		return (ft_string_process(fdata));
	else if (fdata->type == 'p')
		return (ft_ulong_process(fdata));
	else if (fdata->type == 'd')
		return (ft_int_process(fdata));
	else if (fdata->type == 'i')
		return (ft_int_process(fdata));
	else if (fdata->type == 'u')
		return (ft_uint_process(fdata));
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
	
	fdata->blen = ft_formatlen_noarg(format);
	fdata->buf = ft_calloc(fdata->blen, sizeof(char));
	i = 0;
	while (*format)
	{	
		if (*format == '%')
		{
			format = ft_eval_format(format, fdata);
			// print_data(fdata);	//test
			// printf("test : %s\n", fdata->current);   //test
			if (ft_process_format(fdata) == -1)
				return (-1);
			// print_data(fdata);	//test
			i += fdata->clen;
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
