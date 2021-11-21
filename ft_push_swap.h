/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:34:29 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/22 00:45:52 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

void	test(void);
void	elswap(t_dlist *dl);
void	elpush(t_dlist *a, t_dlist *b);
void	elrotate(t_dlist *dl);
void	elreverse(t_dlist *dl);
void	do_op(t_dlist *a, t_dlist *b, char *op);

void	print_stacks(t_dlist *a, t_dlist *b);

#endif
