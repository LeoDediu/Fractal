/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:31:41 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:58:43 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;

	subs = NULL;
	i = 0;
	if (s)
	{
		subs = ft_strnew(len);
		if (subs)
		{
			while (i != len && s[start] != '\0')
			{
				subs[i] = s[start];
				start++;
				i++;
			}
			subs[i] = '\0';
		}
	}
	return (subs);
}
