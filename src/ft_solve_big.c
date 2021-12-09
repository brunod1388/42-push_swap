/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:39:44 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/09 15:28:56 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

typedef struct s_info
{
	int	nb_chunk;
	int	*chunk_tab[25];
	int	chunk_size[25];
	int	small_chunk_id;
	int	big_chunk_id;
	int	small_count;
	int	big_count;
}		t_info;

void	ft_infoinit(t_info *info, int *i_tab, int size)
{
	int	i;

	info->nb_chunk = 1 + ft_sqrt(size) / 2 + size / 100;
	info->big_chunk_id = info->nb_chunk / 2;
	info->small_chunk_id = info->nb_chunk / 2 - 1;
	i = 0;
	info->chunk_tab[0] = i_tab;
	info->chunk_size[0] = size / info->nb_chunk + 1;
	while (++i < info->nb_chunk)
	{
		info->chunk_size[i] = info->chunk_size[i - 1];
		if (i == size % info->nb_chunk)
			info->chunk_size[i]--;
		info->chunk_tab[i] = info->chunk_tab[i - 1] + info->chunk_size[i - 1];
	}
	info->small_count = 0;
	info->big_count = 0;
}

void	ft_process_info(t_info *info, int *count, int is_big)
{
	if (is_big)
	{
		if (++info->big_count == info->chunk_size[info->big_chunk_id])
		{
			if (++info->big_chunk_id == info->nb_chunk)
				*count = INT_MAX;
			info->big_count = 0;
		}
	}
	else
	{
		if (++info->small_count == info->chunk_size[info->small_chunk_id])
		{
			if (--info->small_chunk_id < 0)
				*count = INT_MAX;
			info->small_count = 0;
		}
	}
}

void	ft_setchunk(t_stacks *stacks, int *i_tab, int size)
{
	t_info	info;
	int		close_small;
	int		close_big;

	ft_infoinit(&info, i_tab, size);
	while (stacks->a->length)
	{
		if (info.small_chunk_id > -1)
			close_small = ft_getclosest(stacks->a, info.chunk_tab[info.small_chunk_id],
					info.chunk_size[info.small_chunk_id]);
		if (info.big_chunk_id < info.nb_chunk)
			close_big = ft_getclosest(stacks->a, info.chunk_tab[info.big_chunk_id],
					info.chunk_size[info.big_chunk_id]);
		if (ft_abs(close_big) <= ft_abs(close_small))
		{
			ft_pushclosest(stacks, close_big, 1);
			ft_process_info(&info, &close_big, 1);
		}
		else
		{
			ft_pushclosest(stacks, close_small, 1);
			ft_process_info(&info, &close_small, 0);
			do_op(stacks, RB);
		}
	}
}

int	ft_ontheway(t_stacks *stacks, int nb_op, int n)
{
	char	*op;
	int		to_swap;

	if (nb_op < 0)
		op = ft_strdup(RRB);
	else
		op = ft_strdup(RB);
	if (nb_op < 0)
		nb_op = -nb_op;
	to_swap = 0;
	while (nb_op--)
	{
		if (!to_swap && *(int *) stacks->b->first->content == n)
		{
			do_op(stacks, PA);
			if (op[1] == 'r')
				do_op (stacks, op);
			to_swap = 1;
		}
		else
			do_op (stacks, op);
	}
	free(op);
	return (to_swap);
}

void	ft_solvebig(t_stacks *stacks)
{
	int	*it;
	int	to_swap;
	int	op;

	it = ft_dltoit(stacks->a);
	ft_quicksort(it, stacks->a->length);
	ft_setchunk(stacks, it, stacks->a->length);
	while (stacks->b->length)
	{
		to_swap = 0;
		op = ft_getclosest(stacks->b, it + stacks->b->length - 1, 1);
		if (stacks->b->length > 1)
		{
			to_swap = ft_ontheway(stacks, op, it[stacks->b->length - 2]);
			do_op(stacks, PA);
		}
		else
			ft_pushclosest(stacks, op, 0);
		if (to_swap)
			do_op(stacks, SA);
	}
	free(it);
}
