/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:57:12 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:52:38 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t n;

	i = 0;
	n = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i] == needle[n] && i < len && needle[n] && haystack[i])
		{
			i++;
			n++;
		}
		if (n == ft_strlen(needle))
			return ((char *)(haystack + i - n));
		i = i - n + 1;
		n = 0;
	}
	return (NULL);
}
