/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:49:09 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 18:51:29 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, \
					int c, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdst;
	unsigned char	ch;
	size_t			i;

	i = 0;
	ch = (unsigned char)c;
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == (unsigned char)c)
			return (&cdst[i + 1]);
		i++;
	}
	return (NULL);
}
