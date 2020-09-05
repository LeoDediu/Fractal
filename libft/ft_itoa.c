/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:50:15 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:22:26 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*helper(char *res, int n, int len)
{
	if (n < 0)
	{
		res[0] = '-';
		if (n == -2147483648)
		{
			res[len] = '8';
			n = 214748364;
			len--;
		}
		else
			n = -n;
	}
	if (n == 0)
		res[len] = '0';
	while (n != 0)
	{
		res[len] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char		*res;
	int			len;

	res = NULL;
	len = ft_intlen(n);
	res = malloc(sizeof(char) * (len + 1));
	if (res != NULL)
	{
		res[len] = '\0';
		len = len - 1;
		res = helper(res, n, len);
	}
	return (res);
}
