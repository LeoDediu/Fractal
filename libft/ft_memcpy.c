/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:10:06 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:30:09 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*csrc;
	char	*cdst;
	size_t	i;

	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	csrc = (char *)src;
	cdst = (char *)dst;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
