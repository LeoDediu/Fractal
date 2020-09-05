/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:03:10 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:28:16 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	unsigned char		ch;
	size_t				i;

	i = 0;
	str = (unsigned const char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (ch == str[i])
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
