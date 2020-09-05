/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 12:51:08 by ldediu            #+#    #+#             */
/*   Updated: 2020/02/02 12:51:10 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		zoom(int key, int x, int y, t_fract *st)
{
	float	m_x;
	float	m_y;
	float	zoom;
	float	zoom_coef;

	m_x = (float)x / (WIN_W / (st->max_re - st->min_re)) + st->min_re;
	m_y = (float)y / (WIN_H / (st->max_im - st->min_im)) * -1 + st->max_im;
	if (key == M_SCROLL_DOWN)
		zoom = 0.80;
	else if (key == M_SCROLL_UP)
		zoom = 1.20;
	zoom_coef = 1.0 / zoom;
	st->min_re = (st->min_re - m_x) * zoom_coef + m_x;
	st->max_re = (st->max_re - m_x) * zoom_coef + m_x;
	st->min_im = (st->min_im - m_y) * zoom_coef + m_y;
	st->max_im = (st->max_im - m_y) * zoom_coef + m_y;
	start(st);
}

void		detalization(int key, t_fract *st)
{
	if (key == M_LEFT_CLICK)
		st->max_iter--;
	else if (key == M_RIGHT_CLICK)
		st->max_iter++;
	start(st);
}

int			julia_control(int x, int y, t_fract *st)
{
	st->j_re = 4 * ((float)x / WIN_W - 0.5);
	st->j_im = 4 * ((float)(WIN_H - y) / WIN_H - 0.5);
	start(st);
	return (0);
}

int			mouse(int key, int x, int y, t_fract *st)
{
	if (key == M_SCROLL_UP || key == M_SCROLL_DOWN)
	{
		zoom(key, x, y, st);
	}
	else if (key == M_LEFT_CLICK || key == M_RIGHT_CLICK)
	{
		detalization(key, st);
	}
	return (0);
}

void		choose_help(void)
{
	ft_putstr("Press 1 for 'Mandelbrot', 2 for 'Julia', ");
	ft_putstr("3 for 'Burning Ship', 4 for 'Mandelbar', 5 for 'Buffalo'\n");
}
