/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:47:35 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:24:39 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *headnew;

	if (!lst)
		return (NULL);
	headnew = f(lst);
	newlist = headnew;
	lst = lst->next;
	while (lst)
	{
		newlist->next = f(lst);
		lst = lst->next;
		newlist = newlist->next;
	}
	return (headnew);
}
