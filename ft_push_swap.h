/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:34:29 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/09 17:41:00 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include "libft/libft.h"
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# include <limits.h>

typedef struct s_stacks
{
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*solution;
}	t_stacks;

void	do_op(t_stacks *stacks, char *op);
void	do_nbop(t_stacks *stacks, int n, char *op);

void	ft_solve(t_stacks *stacks);
void	ft_solvebig(t_stacks *stacks);

int		ft_ischunk(int n, int *i_tab, int size);
void	ft_pushclosest(t_stacks *stacks, int op, int a_to_b);
int		ft_getclosest(t_dlist *a, int *i_tab, int size);

t_dlist	*ft_atodl(int argc, char **argv);
t_dlist	*ft_sttodl(char *s);
int		ft_isdlok(t_dlist *dl);

int		ft_isbigger(t_node *a, t_node *b);
int		*ft_dltoit(t_dlist *dl);

void	print_stacks(t_stacks *stacks);
void	set_counter(int i);
int		get_counter(void);
void	ft_printsol(t_stacks *stacks);

#endif
