/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:04:16 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/08 15:00:43 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_fdata_init(t_fdata *fdata)
{
	fdata->plus = 0;
	fdata->minus = 0;
	fdata->zero = 0;
	fdata->space = 0;
	fdata->hash = 0;
	fdata->dot = 0;
	fdata->width = 0;
	fdata->precision = 0;
	fdata->clen = 0;
}

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

int	ft_fix_plusminus(t_fdata *fdata)
{
	char *sign;

	sign = ft_memchr(fdata->current, '-', fdata->clen);
	if (sign)
	{
		fdata->current[0] = *sign;
		*sign = '0';
		return (0);
	}
	sign = ft_memchr(fdata->current, '+', fdata->clen);
	if (sign)
	{
		fdata->current[0] = *sign;
		*sign = '0';
	}
	return (0);
}
