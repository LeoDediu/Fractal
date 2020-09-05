/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:53:42 by ldediu            #+#    #+#             */
/*   Updated: 2020/02/25 16:53:42 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void			paint(t_fract *st, int i, int x, int y)
{
	float		t;
	int			r;
	int			g;
	int			b;

	t = (float)i / (float)st->max_iter;
	r = (int)(8 * st->col_coef * (1 - t) * t * t * t * 255);
	g = (int)(14 * st->col_coef * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(6 * st->col_coef * (1 - t) * (1 - t) * (1 - t) * t * 255);
	i = (x * 4) + (y * WIN_W * 4);
	if (t > 0.8 && t <= 1.0)
	{
		st->data[i] = (char)0;
		st->data[++i] = (char)0;
		st->data[++i] = (char)0;
		st->data[++i] = (char)0;
	}
	else
	{
		st->data[i] = (char)b;
		st->data[++i] = (char)g;
		st->data[++i] = (char)r;
		st->data[++i] = (char)0;
	}
}
