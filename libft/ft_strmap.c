/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:38:54 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:47:22 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ns;

	i = 0;
	ns = NULL;
	if (s && f)
	{
		ns = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (ns != NULL)
		{
			while (s[i] != '\0')
			{
				ns[i] = f(s[i]);
				i++;
			}
			ns[i] = '\0';
		}
	}
	return (ns);
}
