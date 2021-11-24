/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:34:29 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/24 22:53:56 by bgoncalv         ###   ########.fr       */
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

void	do_op(t_dlist *a, t_dlist *b, char *op);
void	do_nbop(t_dlist *a, t_dlist *b, int n, char *op);

t_dlist	*ft_atodl(int argc, char **argv);

void	print_stacks(t_dlist *a, t_dlist *b);
size_t	ft_dl_getmini(t_dlist *dl, size_t l);
size_t	ft_dl_getmaxi(t_dlist *dl, size_t l);
int		ft_isbigger(t_node *a, t_node *b);
void	ft_solve(t_dlist *a, t_dlist *b);
void	ft_solvebig(t_dlist *a, t_dlist *b);
int		*ft_dltoit(t_dlist *dl);

void	printArray(int arr[], int size);

#endif
