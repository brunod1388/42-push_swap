/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:00:49 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/21 23:14:07 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

// void	do_op(t_list **a, t_list **b, char *op)
// {
// 	if (op[0] == 's')
// 	{
// 		if (op[1] == 'a' || op[1] == 's')
// 			elswap(*a);
// 		if (op[1] == 'b' || op[1] == 's')
// 			elswap(*b);
// 	}
// 	else if (op[0] == 'p' && op[1] == 'b')
// 		elpush(b, a);
// 	else if (op[0] == 'p' && op[1] == 'a')
// 		elpush(a, b);
// 	else if (ft_strlen(op) == 2 && op[0] == 'r')
// 	{
// 		if (op[1] == 'a' || op[1] == 'r')
// 			elrotate(a);
// 		if (op[1] == 'a' || op[1] == 'r')
// 			elrotate(b);
// 	}
// 	else if (ft_strlen(op) == 3 && op[0] == 'r' && op[1] == 'r')
// 	{
// 		if (op[2] == 'a' || op[2] == 'r')
// 			elreverse(a);
// 		if (op[2] == 'a' || op[2] == 'r')
// 			elreverse(b);
// 	}
// }



int	main(int argc, char **argv)
{
	t_dlist	*dl1;
	t_dlist	*dl2, *dl3;
	int		*pi;
	int 	i;

	dl1 = NULL;
	ft_printdlsti(dl1, 1);
	ft_printf("DLST init\n");
	dl1 = ft_dlnew();
	ft_printdlsti(dl1, 1);
	ft_printf("DLST addlast\n");
	i = 0;
	while(i < 5)
	{
		pi = malloc(sizeof(int));
		*pi = i;
		ft_dladdlast(dl1, pi);
		i++;
	}
	ft_printdlsti(dl1, 1);
	dl2 = ft_dlnew();
	i = 10;
	while(i < 15)
	{
		pi = malloc(sizeof(int));
		*pi = i;
		ft_dladdfirst(dl2, pi);
		i++;
	}
	dl3 = ft_dlnew();
	i = 1;
	while(i < argc)
	{
		pi = malloc(sizeof(int));
		*pi = ft_atoi(argv[i]);
		ft_dladdlast(dl3, pi);
		i++;
	}
	ft_printf("\nINITIALISATION\n");
	ft_printf("-----------------------------------\n");
	ft_printf("dl1:\n");
	ft_printdlsti(dl1, 0);
	ft_printf("-----------------------------------\n");
	ft_printf("dl2:\n");
	ft_printdlsti(dl2, 0);
	ft_printf("-----------------------------------\n");
	ft_printf("dl3:\n");
	ft_printdlsti(dl3, 0);
	ft_printf("-----------------------------------\n");

	ft_dlputfirst(dl1, ft_dlpushfirst(dl2));
	ft_dlputfirst(dl1, ft_dlpushfirst(dl2));
	ft_dlputfirst(dl1, ft_dlpushfirst(dl2));

	ft_dlputfirst(dl3, ft_dlpushlast(dl3));	
	ft_dlputfirst(dl3, ft_dlpushlast(dl3));

	ft_printf("\nfew rotations\n");
	ft_printf("-----------------------------------\n");
	ft_printf("dl1:\n");
	ft_printdlsti(dl1, 1);
	ft_printf("-----------------------------------\n");
	ft_printf("dl2:\n");
	ft_printdlsti(dl2, 1);
	ft_printf("-----------------------------------\n");
	ft_printf("dl3:\n");
	ft_printdlsti(dl3, 1);
	ft_printf("-----------------------------------\n");

	ft_dlputfirst(dl1, ft_dlpushlast(dl2));
	ft_dlputfirst(dl1, ft_dlpushlast(dl2));

	ft_printf("\n\n\n");
	ft_printf("-----------------------------------\n");
	ft_printf("dl1:\n");
	ft_printdlsti(dl1, 1);
	ft_printf("-----------------------------------\n");
	ft_printf("dl2:\n");
	ft_printdlsti(dl2, 1);
	ft_printf("-----------------------------------\n");
	ft_printf("dl3:\n");
	ft_printdlsti(dl3, 1);
	ft_printf("-----------------------------------\n");

	ft_dlclear(&dl1);
	ft_dlclear(&dl2);
	ft_dlclear(&dl3);
	// while (1);
	return (0);
}