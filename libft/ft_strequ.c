/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:07:17 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:42:10 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i] == s2[i] && s2[i] != '\0' && s1[i] != '\0')
			i++;
		res = (char)s1[i] - (char)s2[i];
		if (res == 0)
			res = 1;
		else
			res = 0;
	}
	return (res);
}
