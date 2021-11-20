/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_testui.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:00:49 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/20 00:35:02 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	elswap(t_list *l)
{
	void	*tmp;
	
	tmp = l->next->content;
	l->next->content = l->content;
	l->content = tmp;
}

void	elpush(t_list **a, t_list **b)
{
	t_list	*tmp;
	
	if (!*b)
		return ;
	tmp = (*b)->next;
	(*b)->next = NULL;
	ft_lstadd_front(a,*b);
	*b = tmp;
}

void elrotate(t_list **l)
{
	t_list	*tmp;

	if (!*l || !(*l)->next)
		return ;
	tmp = (*l)->next;
	(*l)->next = NULL;
	ft_lstadd_back(&tmp, *l);
	*l = tmp;
}

void	elreverse(t_list **l)
{
	t_list	*prelast;

	if (!*l || !(*l)->next)
		return ;
	prelast = ft_lstprelast(*l);
	ft_lstadd_front(l, prelast->next);
	prelast->next = NULL;
}

void	do_op(t_list **a, t_list **b, char *op)
{
	if (op[0] == 's')
	{
		if (op[1] == 'a' || op[1] == 's')
			elswap(*a);
		if (op[1] == 'b' || op[1] == 's')
			elswap(*b);
	}
	else if (op[0] == 'p' && op[1] == 'b')
		elpush(b, a);
	else if (op[0] == 'p' && op[1] == 'a')
		elpush(a, b);
	else if (ft_strlen(op) == 2 && op[0] == 'r')
	{
		if (op[1] == 'a' || op[1] == 'r')
			elrotate(a);
		if (op[1] == 'a' || op[1] == 'r')
			elrotate(b);
	}
	else if (ft_strlen(op) == 3 && op[0] == 'r' && op[1] == 'r')
	{
		if (op[2] == 'a' || op[2] == 'r')
			elreverse(a);
		if (op[2] == 'a' || op[2] == 'r')
			elreverse(b);
	}
}

int	main(int argc, char **argv)
{	
	int i;
	t_list *a;
	t_list *b;
	
	if (argc < 3)
	{
		ft_printf("enter at least two args\n");
		return (0);
	}
	i = 0;
	a = NULL;
	b = NULL;
	while (argc-- > 1)
	{
		ft_lstadd_front(&a, ft_lstnew(argv[argc]));
	}
	// ft_printf("----------------------------------------\n");
	// ft_printf("Init a and b:\n");
	// print_stacks(a, b);
	// ft_printf("----------------------------------------\n");
	// ft_printf("Exec sa:\n");
	// elswap(a);
	// print_stacks(a, b);
	// ft_printf("----------------------------------------\n");
	// ft_printf("Exec pb pb pb\n");
	// elpush(&b, &a);
	// elpush(&b, &a);
	// elpush(&b, &a);
	// print_stacks(a, b);
	// ft_printf("----------------------------------------\n");
	// ft_printf("Exec ra rb\n");
	// elrotate(&a);
	// elrotate(&b);
	// print_stacks(a, b);
	// ft_printf("----------------------------------------\n");
	// ft_printf("Exec rra rrb\n");
	// elreverse(&a);
	// elreverse(&b);
	// print_stacks(a, b);
	// ft_printf("----------------------------------------\n");
	// ft_printf("Exec sa:\n");
	// elswap(a);
	// print_stacks(a, b);
	// ft_printf("----------------------------------------\n");
	// ft_printf("Exec pa pa pa\n");
	// elpush(&a, &b);
	// elpush(&a, &b);
	// elpush(&a, &b);
	// print_stacks(a, b);


	ft_printf("----------------------------------------\n");
	ft_printf("Init a and b:\n");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec sa:\n");
	do_op(&a, &b, "sa");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec pb pb pb\n");
	do_op(&a, &b, "pb");
	do_op(&a, &b, "pb");
	do_op(&a, &b, "pb");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec ra rb\n");
	do_op(&a, &b, "ra");
	do_op(&a, &b, "rb");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec rra rrb\n");
	do_op(&a, &b, "rra");
	do_op(&a, &b, "rrb");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec sa:\n");
	do_op(&a, &b, "sa");
	print_stacks(a, b);
	ft_printf("----------------------------------------\n");
	ft_printf("Exec pa pa pa\n");
	do_op(&a, &b, "pa");
	do_op(&a, &b, "pa");
	do_op(&a, &b, "pa");
	print_stacks(a, b);
	return (0);
}