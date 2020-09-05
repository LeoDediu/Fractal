/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:38:01 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:44:50 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	int		i;
	int		j;

	i = 0;
	j = 0;
	news = NULL;
	if (s1 && s2)
	{
		news = (char *)malloc(sizeof(char) * (ft_strlen(s1) + \
				ft_strlen(s2) + 1));
		if (!news)
			return (NULL);
		while (s1[i] != 0)
			news[j++] = s1[i++];
		i = 0;
		while (s2[i] != 0)
			news[j++] = s2[i++];
		news[j] = '\0';
	}
	return (news);
}
