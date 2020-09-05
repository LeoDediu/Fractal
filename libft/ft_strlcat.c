/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:15:52 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:45:41 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t n;
	size_t res;

	n = ft_strlen(dst);
	res = ft_strlen(src);
	if (dstsize < n)
		res += dstsize;
	else
		res += n;
	while (*src && n + 1 < dstsize)
	{
		dst[n++] = *src;
		src++;
	}
	dst[n] = '\0';
	return (res);
}
