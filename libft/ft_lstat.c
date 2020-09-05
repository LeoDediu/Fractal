/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:25:41 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/03 12:25:42 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *begin_list, unsigned int nbr)
{
	unsigned int n;

	n = 0;
	while (begin_list)
	{
		if (n == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		n++;
	}
	return (0);
}
