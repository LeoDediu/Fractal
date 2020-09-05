/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:55:45 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:48:22 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				ns[i] = f(i, s[i]);
				i++;
			}
			ns[i] = '\0';
		}
	}
	return (ns);
}
