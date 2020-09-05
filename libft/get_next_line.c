/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:26:22 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/07 12:26:43 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*helper(char **s, int fd)
{
	int			i;
	char		*out;
	char		*temp;

	i = 0;
	out = NULL;
	temp = NULL;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		out = ft_strsub(s[fd], 0, i);
		temp = ft_strdup(&(s[fd][i + 1]));
		free(s[fd]);
		s[fd] = temp;
	}
	else
	{
		out = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (out);
}

int				get_next_line(const int fd, char **line)
{
	static char	*s[FD_SIZE];
	char		*temp;
	char		buff[BUFF_SIZE + 1];
	int			res;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(1);
	res = 0;
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		temp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = temp;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (res == 0 && (!s[fd] || s[fd][0] == '\0'))
		return (0);
	*line = helper(s, fd);
	return (1);
}
