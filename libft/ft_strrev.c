/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:50:41 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:53:39 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	repo;

	i = -1;
	len = 0;
	while (str[len] != 0)
		len++;
	if (len < 1)
		return (str);
	while (--len >= ++i)
	{
		repo = str[len];
		str[len] = str[i];
		str[i] = repo;
	}
	return (str);
}
