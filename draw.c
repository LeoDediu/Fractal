/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:10:07 by ldediu            #+#    #+#             */
/*   Updated: 2020/01/20 16:10:08 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_complex		init_complex_num(float re, float im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

float			choose_more_fract_re(t_fract *st, float old_re, float old_im)
{
	float		re;

	if (st->fract_type == 3)
		re = (old_re * old_re) - (old_im * old_im) + st->pix_re;
	else if (st->fract_type == 4)
		re = (old_re * old_re) - (old_im * old_im) + st->pix_re;
	else if (st->fract_type == 5)
		re = fabs((old_re * old_re) - (old_im * old_im)) + st->pix_re;
	return (re);
}

float			choose_more_fract_im(t_fract *st, float old_re, float old_im)
{
	float		im;

	if (st->fract_type == 3)
		im = -2.0 * fabs(old_re * old_im) + st->pix_im;
	else if (st->fract_type == 4)
		im = -2.0 * old_re * old_im + st->pix_im;
	else if (st->fract_type == 5)
		im = -2.0 * old_re * fabs(old_im) + st->pix_im;
	return (im);
}

t_complex		choose_fract(t_fract *st, float old_re, float old_im)
{
	float		re;
	float		im;

	if (st->fract_type == 1)
	{
		re = (old_re * old_re) - (old_im * old_im) + st->pix_re;
		im = 2.0 * old_re * old_im + st->pix_im;
	}
	else if (st->fract_type == 2)
	{
		re = (old_re * old_re) - (old_im * old_im) + st->j_re;
		im = 2.0 * old_re * old_im + st->j_im;
	}
	else if (st->fract_type == 3 || st->fract_type == 4 || st->fract_type == 5)
	{
		re = choose_more_fract_re(st, old_re, old_im);
		im = choose_more_fract_im(st, old_re, old_im);
	}
	return (init_complex_num(re, im));
}

void			draw(t_fract *st)
{
	int			i;
	int			y;
	int			x;
	t_complex	z;

	y = st->start;
	while (y < st->finish)
	{
		st->pix_im = st->max_im - y * st->complnum_to_pix;
		x = 0;
		while (x < WIN_W)
		{
			i = 0;
			st->pix_re = st->min_re + x * st->complnum_to_pix;
			z = init_complex_num(st->pix_re, st->pix_im);
			while ((z.re * z.re + z.im * z.im) < 4 && i < st->max_iter)
			{
				z = choose_fract(st, z.re, z.im);
				i++;
			}
			paint(st, i, x, y);
			x++;
		}
		y++;
	}
}
