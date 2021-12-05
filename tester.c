/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:30:50 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/05 02:08:55 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_push_swap.h"
#include <time.h>
#include <stdlib.h>

typedef struct s_stat {
	int		counter_ok;
	double	mv_avg;
	int		mv_nb;
	int		max_move;
	int		min_move;
}	t_stat;

int	ft_pstester(int nb, int min, int max)
{
	t_dlist	*a;
	t_dlist	*b;
	int		*i;
	int		nb_mv;

	a = ft_dlnew();
	b = ft_dlnew();
	while (nb--)
	{
		i = malloc(sizeof(int));
		if (!i)
			return (0);
		*i = min + rand() % (max - min);
		ft_dladdfirst(a, i);
	}
	set_counter(0);
	ft_solve(a, b);
	nb_mv = get_counter();
	if (!ft_dlisordered(a, ft_isbigger) || b->length)
		nb_mv = -1;
	ft_dlclear(&a);
	ft_dlclear(&b);
	return (nb_mv);
}

void	print_result(int nb_test, t_stat *stat, int nb_val)
{
	stat->mv_avg = stat->mv_avg / stat->counter_ok;
	ft_printf("Result for stack of %i element :\n\n", nb_val);
	ft_printf("minimum move    : %5i\n", stat->min_move);
	ft_printf("maximum move    : %5i\n", stat->max_move);
	ft_printf("nb move average : %5i (%f)\n\n",
		(int) stat->mv_avg, stat->mv_avg);
	ft_printf("nb test OK      : %5i / %i\n", stat->counter_ok, nb_test);
}

void	ps_test(int nb_val, int nb_test, int min, int max)
{
	int		i;
	t_stat	stat;

	i = 0;
	stat.counter_ok = 0;
	stat.mv_avg = 0;
	stat.max_move = 0;
	stat.min_move = 100000;
	while (i++ < nb_test)
	{
		stat.mv_nb = (double) ft_pstester(nb_val, min, max);
		if (stat.mv_nb > stat.max_move)
			stat.max_move = stat.mv_nb;
		if (stat.mv_nb < stat.min_move)
			stat.min_move = stat.mv_nb;
		if (stat.mv_nb >= 0)
		{
			stat.mv_avg += stat.mv_nb;
			stat.counter_ok++;
		}
	}
	print_result(nb_test, &stat, nb_val);
}

int	main(int argc, char **argv)
{
	srand((unsigned) time(NULL));
	if (argc != 4)
	{
		ft_printf("Three args needed ; nb test, int min, int max\n");
		return (0);
	}
	ft_printf("\n***********************************\n");
	ft_printf("******                       ******\n");
	ft_printf("******      Big  Test        ******\n");
	ft_printf("******                       ******\n");
	ft_printf("***********************************\n\n");
	ps_test(3, ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	ft_printf("\n***********************************\n\n");
	ps_test(5, ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	ft_printf("\n***********************************\n\n");
	ps_test(100, ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	ft_printf("\n***********************************\n\n");
	ps_test(500, ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	ft_printf("\n***********************************\n\n");
	return (0);
}
