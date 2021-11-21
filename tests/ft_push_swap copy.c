/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:00:49 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/21 03:57:27 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct s_element
{
	struct s_element	*up;
	struct s_element	*down;
	void				*content;
} t_element;

typedef struct s_stack
{
	struct s_element	*top;
	struct s_element	*bottom;
}	t_stack;

t_stack	*ft_stkinit(void)
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->bottom = NULL;
	st->top = NULL;
	return (st);
}

void	ft_stkadd(t_stack *st, void *content)
{
	t_element	*el;

	el = malloc(sizeof(t_element));
	if (!el)
		return ;
	el->up = NULL;
	el->down = st->top;
	st->top->up = el;
	st->top = el;
	el->content = content;
}

void	elswap(t_stack *st)
{
	void	*tmp;
	
	if (!st->top && !st->top->down)
		return ;
	tmp = st->top->content;
	st->top->content = st->top->down->content;
	st->top->down->content = tmp;
}

void	elpush(t_stack *a, t_stack *b)
{
	t_element	*nbhead;
	
	if (!b && !b->top)
		return ;
	nbhead = b->top->down;
	nbhead->up = NULL;
	a->top->up = b->top;
	a->top = b->top;
	b->top = nbhead;
	if (!b->top->down)
		b->bottom = b->top;
}

//to finish if chosen path
void elrotate(t_stack *st)
{
	t_element	*nbhead;
	
	if (!b && !b->top)
		return ;
	nbhead = b->top->down;
	nbhead->up = NULL;
	b->top->down = a->top;
	a->top->up = b->top;
	a->top = b->top;
	b->top = nbhead;

void	elreverse(t_stack **l)
{
	t_stack	*prelast;

	if (!*l || !(*l)->next)
		return ;
	prelast = ft_lstprelast(*l);
	ft_lstadd_front(l, prelast->next);
	prelast->next = NULL;
}

void	do_op(t_stack **a, t_stack **b, char *op)
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

t_stack	*ft_atoli(int argc, char **argv)
{
	t_stack	*l;
	int		*pi;

	if (argc < 2)
		return (NULL);
	while (argc-- > 1)
	{	
		pi = malloc(sizeof(int));
		if (!pi || !ft_isnumber(argv[argc]))
		{
			ft_lstclear(&l, free);
			return (NULL);
		}
		*pi = ft_atoi(argv[argc]);
		ft_lstadd_front(&l, ft_lstnew(pi));
	}
	return (l);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int		sizea;
	int		sizeb;
	char	*acontent;
	char	*bcontent;
	int		i;

	sizea = ft_lstsize(a);
	sizeb = ft_lstsize(b);
	i = 0;
	while (i < sizea || i < sizeb)
	{
		acontent = ft_getnblist(a, i);
		bcontent = ft_getnblist(b, i);
		if (acontent && bcontent)
			ft_printf("%d %d\n", *acontent, *bcontent);
		if (acontent && !bcontent)
			ft_printf("%d\n", *acontent);
		if (!acontent && bcontent)
			ft_printf("%s %d\n", " ", *bcontent);
		i++;
	}
	ft_printf("_ _\n");
	ft_printf("a b\n");
}

int	main(int argc, char **argv)
{	
	int i;
	t_stack *a;
	t_stack *b;
	
	if (argc < 3)
	{
		ft_printf("enter at least two args\n");
		return (0);
	}
	i = 0;
	a = NULL;
	b = NULL;
	a = ft_atoli(argc, argv);
	// while (argc-- > 1)
	// {
	// 	ft_lstadd_front(&a, ft_lstnew(argv[argc]));
	// }
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