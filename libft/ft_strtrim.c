/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:29:22 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 16:59:48 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*news;
	int		fnsh;

	i = 0;
	fnsh = 0;
	news = NULL;
	if (s)
	{
		fnsh = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i] == '\0')
			return (ft_strnew(1));
		while (s[fnsh] == ' ' || s[fnsh] == '\n' || s[fnsh] == '\t')
			fnsh--;
		news = (char *)malloc(sizeof(char) * (fnsh - i + 1));
		if (news == NULL)
			return (NULL);
		news = ft_strsub(s, i, fnsh - i + 1);
	}
	return (news);
}
