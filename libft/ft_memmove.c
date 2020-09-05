/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:39:55 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:31:44 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;
	size_t	i;

	csrc = (char *)src;
	cdst = (char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src < dst)
	{
		i = len + 1;
		while (--i > 0)
			cdst[i - 1] = csrc[i - 1];
	}
	else
	{
		i = -1;
		while (++i < len)
			cdst[i] = csrc[i];
	}
	return (dst);
}
