/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:34:29 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/12/04 03:53:00 by bgoncalv         ###   ########.fr       */
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

void	ft_solve(t_dlist *a, t_dlist *b);
void	ft_solve3(t_dlist *a, t_dlist *b);

void	do_op(t_dlist *a, t_dlist *b, char *op);
void	do_nbop(t_dlist *a, t_dlist *b, int n, char *op);
t_dlist	*ft_atodl(int argc, char **argv);
int		ft_isbigger(t_node *a, t_node *b);
void	ft_solvebig(t_dlist *a, t_dlist *b);
int		ft_getclosest(t_dlist *a, int *i_tab, int size);
int		*ft_dltoit(t_dlist *dl);

void	print_stacks(t_dlist *a, t_dlist *b);
void	set_counter(int i);
int		get_counter(void);

#endif
