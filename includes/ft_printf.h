/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:33:36 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/08 15:02:08 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# define FORMAT_LIST "cspdiuxX%"
# define FLAGS_LIST "-# +0"

#include <stdio.h>

typedef struct	s_fdata
{
	va_list	ap;
	int		plus;
	int		minus;
	int		zero;
	int		space;
	int		hash;
	int		dot;
	int		width;
	int		precision;
	char	type;
	int		clen;
	int		blen;
	char	*current;
	char	*buf;
}			t_fdata;

int		ft_printf(const char *format, ...);

int	ft_printf_format(char *format, t_fdata *fdata);
char		*ft_eval_flag(char *format, t_fdata *fdata);
char		*ft_eval_flags(char *format, t_fdata *fdata);
int			ft_process_format(t_fdata *fdata);
int			ft_formatlen_noarg(char *s);

void	ft_fdata_init(t_fdata *fdata);
int		ft_addprefix(t_fdata *fdata, char fillchar, int nb_fillchar);
int		ft_addsufix(t_fdata *fdata, char fillchar, int nb_fillchar);
int		ft_addarg(t_fdata *fdata);
int		ft_fix_plusminus(t_fdata *fdata);

int		ft_int_process(t_fdata *fdata);
int		ft_uint_process(t_fdata *fdata);
int		ft_ulong_process(t_fdata *fdat);
int		ft_hex_process(t_fdata *fdata);
int		ft_char_process(t_fdata *fdata);
int		ft_percent_process(t_fdata *fdata);
int		ft_string_process(t_fdata *fdata);

int		ft_width_process(t_fdata *fdata);
int		ft_space_process(t_fdata *fdata);
int		ft_hash_process(t_fdata *fdata);
int		ft_plus_process(t_fdata *fdata);
int		ft_precision_string_process(t_fdata *fdata);
int		ft_precision_number_process(t_fdata *fdata);

#endif