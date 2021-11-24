/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:00:49 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/24 02:35:55 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"


void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		ft_printf("%d ", arr[i]);
	ft_printf("\n");
}

int	ft_isbigger(t_node *a, t_node *b)
{
	return (*(int *)a->content > *(int *)b->content);
}

int	main(int argc, char **argv)
{
	t_dlist	*dl1;
	t_dlist	*dl2, *dl3;
	int		*pi;
	int		i;

	dl1 = NULL;
	ft_printdlsti(dl1, 1, ft_isbigger);
	ft_printf("DLST init\n");
	dl1 = ft_dlnew();
	ft_printdlsti(dl1, 1, ft_isbigger);
	ft_printf("DLST addlast\n");
	i = 0;
	while(i < 5)
	{
		pi = malloc(sizeof(int));
		*pi = i;
		ft_dladdlast(dl1, pi);
		i++;
	}
	ft_printdlsti(dl1, 1, ft_isbigger);
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
	ft_printdlsti(dl1, 0, ft_isbigger);
	ft_printf("-----------------------------------\n");
	ft_printf("dl2:\n");
	ft_printdlsti(dl2, 0, ft_isbigger);
	ft_printf("-----------------------------------\n");
	ft_printf("dl3:\n");
	ft_printdlsti(dl3, 0, ft_isbigger);
	ft_printf("-----------------------------------\n");

	ft_dlputfirst(dl1, ft_dlpushfirst(dl2));
	ft_dlputfirst(dl1, ft_dlpushfirst(dl2));
	ft_dlputfirst(dl1, ft_dlpushfirst(dl2));

	ft_dlputfirst(dl3, ft_dlpushlast(dl3));	
	ft_dlputfirst(dl3, ft_dlpushlast(dl3));

	ft_printf("\nfew rotations\n");
	ft_printf("-----------------------------------\n");
	ft_printf("dl1:\n");
	ft_printdlsti(dl1, 1, ft_isbigger);
	ft_printf("-----------------------------------\n");
	ft_printf("dl2:\n");
	ft_printdlsti(dl2, 1, ft_isbigger);
	ft_printf("-----------------------------------\n");
	ft_printf("dl3:\n");
	ft_printdlsti(dl3, 1, ft_isbigger);
	ft_printf("-----------------------------------\n");

	ft_dlputfirst(dl1, ft_dlpushlast(dl2));
	ft_dlputfirst(dl1, ft_dlpushlast(dl2));

	ft_printf("\n\n\n");
	ft_printf("-----------------------------------\n");
	ft_printf("dl1:\n");
	ft_printdlsti(dl1, 1, ft_isbigger);
	ft_printf("-----------------------------------\n");
	ft_printf("dl2:\n");
	ft_printdlsti(dl2, 1, ft_isbigger);
	ft_printf("-----------------------------------\n");
	ft_printf("dl3:\n");
	ft_printdlsti(dl3, 1, ft_isbigger);
	ft_printf("-----------------------------------\n");

	ft_dlclear(&dl1);
	ft_dlclear(&dl2);
	ft_dlclear(&dl3);

	int	i_tab1[15] = {1, 23, 56, 46, 545, -5, 4546, 453, 89, 123, 45, 45, 78, 12, 89};
	int	i_tab2[15] = {1, 23, 56, 46, 545, 4546, -5, 453, 89, 123, 45, 45, 78, 12, 89};
	
	printArray(i_tab1, 15);
	ft_quicksort(i_tab2, 15);
	printArray(i_tab2, 15);
	ft_bubsort(i_tab1, 15);
	printArray(i_tab2, 15);

	// while (1);
	return (0);
}