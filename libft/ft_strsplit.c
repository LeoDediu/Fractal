/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:21:01 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/02 18:48:44 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			lettercounter(const char *s, char c)
{
	int		i;

	i = 0;
	if (s && c)
	{
		while (s[i] != c && s[i])
			i++;
	}
	return (i);
}

static const char	*skip(const char *s, char c)
{
	if (s && c)
	{
		while (*s == c)
			s++;
	}
	return (s);
}

static int			wordcounter(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
				count++;
			i++;
		}
	}
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		wc;
	int		lc;
	char	**finarr;

	wc = wordcounter(s, c);
	i = -1;
	finarr = (char**)malloc(sizeof(char *) * wc + 1);
	if (!finarr)
		return (finarr);
	s = skip(s, c);
	while (++i < wc)
	{
		lc = lettercounter(s, c);
		finarr[i] = (char*)malloc(sizeof(char) * lc + 1);
		j = -1;
		while (++j < lc)
			finarr[i][j] = s[j];
		finarr[i][j] = '\0';
		s += lc;
		s = skip(s, c);
	}
	finarr[i] = NULL;
	return (finarr);
}
