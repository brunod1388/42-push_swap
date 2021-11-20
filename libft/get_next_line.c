/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:40:52 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/11/20 00:19:13 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_has_line(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

static char	*ft_getline(char **s)
{
	char	*dst;
	char	*tmp;
	size_t	lleft;
	int		i;

	i = 0;
	while ((*s)[i] && (*s)[i] != '\n')
		i ++;
	if ((*s)[i] == '\n')
		i++;
	dst = malloc(i + 1);
	if (!dst)
		return (NULL);
	dst = ft_strncpy(dst, *s, i + 1);
	lleft = ft_strlen(*s) - i;
	if (lleft)
	{
		tmp = malloc(lleft + 1);
		ft_strncpy(tmp, (*s) + i, lleft + 1);
	}
	else
		tmp = NULL;
	free(*s);
	*s = tmp;
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*sleft[MAX_TAB];
	char		buffer[BUFFER_SIZE];
	size_t		nread;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 0)
		return (NULL);
	while (!ft_has_line(sleft[fd]))
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if ((!nread || nread > BUFFER_SIZE) && !sleft[fd])
			break ;
		sleft[fd] = ft_strljoin(sleft[fd], buffer, nread);
		if (nread < BUFFER_SIZE)
			break ;
		if (!sleft[fd])
			return (NULL);
	}
	if (ft_strlen(sleft[fd]))
		return (ft_getline(&sleft[fd]));
	else if (sleft[fd])
		free(sleft[fd]);
	return (NULL);
}
