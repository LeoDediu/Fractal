/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:50:37 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:25:36 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *p;

	p = NULL;
	if (size)
	{
		p = (unsigned char *)malloc(size);
		if (!p)
			return (NULL);
		ft_bzero(p, size);
	}
	return ((void *)p);
}
