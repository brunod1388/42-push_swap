/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_process2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:45:56 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/08 17:02:27 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
