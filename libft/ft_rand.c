/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 11:34:30 by ldediu            #+#    #+#             */
/*   Updated: 2019/10/03 11:34:31 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_rand(unsigned int n)
{
	static unsigned int	state;
	unsigned int		q;
	unsigned int		rem;
	unsigned int		mod;
	unsigned int		prim;

	mod = 2147483647;
	prim = 48271;
	if (!state)
		state = n;
	q = state / (mod / prim);
	rem = state % (mod / prim);
	if (rem * prim > (mod % prim) * q)
		return ((state = rem * prim - (mod % prim) * q));
	else
		return ((state = mod + rem - (mod % prim) * q));
}
