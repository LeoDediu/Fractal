/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:19:22 by ldediu            #+#    #+#             */
/*   Updated: 2020/01/24 13:19:23 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_error(void)
{
	ft_putstr("This fractal doesn't exist.\n");
	ft_putstr("Choose between 1-5 only.\n");
	exit(0);
}

void	move(int key, t_fract *st)
{
	if (key == KEY_LEFT)
	{
		st->min_re += 0.025;
		st->max_re += 0.025;
	}
	else if (key == KEY_RIGHT)
	{
		st->min_re -= 0.025;
		st->max_re -= 0.025;
	}
	else if (key == KEY_DOWN)
	{
		st->min_im += 0.025;
		st->max_im += 0.025;
	}
	else if (key == KEY_UP)
	{
		st->min_im -= 0.025;
		st->max_im -= 0.025;
	}
}

void	choose(int key, t_fract *st)
{
	if (key == 18)
		st->fract_type = 1;
	else if (key == 19)
		st->fract_type = 2;
	else if (key == 20)
		st->fract_type = 3;
	else if (key == 21)
		st->fract_type = 4;
	else if (key == 23)
		st->fract_type = 5;
	start(st);
}

void	ft_help(void)
{
	ft_putstr("-----------------------HELP-----------------------\n\n");
	ft_putstr("Use arrows to move left/right or up/down.\n");
	ft_putstr("Use mouse wheel to zoom in/zoom out.\n");
	ft_putstr("Press space to change colors.\n");
	ft_putstr("Press left/right mouse click for detalization.\n");
	ft_putstr("Press 1-5 to choose different fractal.\n");
	ft_putstr("Press Esc to quit\n");
	ft_putstr("--------------------------------------------------\n\n");
}

int		keyboard(int key, t_fract *st)
{
	if (key == KEY_ESC)
	{
		ft_putstr("Game Over.\n");
		exit(0);
	}
	else if (key == KEY_LEFT || key == KEY_RIGHT || \
			key == KEY_DOWN || key == KEY_UP)
		move(key, st);
	else if (key == KEY_HELP)
	{
		ft_help();
	}
	else if (key == KEY_SPACE)
		st->col_coef += 0.5;
	else if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23)
		choose(key, st);
	start(st);
	return (0);
}
