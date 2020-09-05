/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:00:05 by ldediu            #+#    #+#             */
/*   Updated: 2020/02/25 16:29:36 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void			multithread(t_fract *st)
{
	pthread_t	new_thread[N_THREADS];
	t_fract		new_st[N_THREADS];
	int			i;

	i = 0;
	while (i < N_THREADS)
	{
		new_st[i] = *st;
		new_st[i].start = i * (WIN_H / N_THREADS);
		new_st[i].finish = (i + 1) * (WIN_H / N_THREADS);
		pthread_create(&new_thread[i], NULL, (void *)draw, (void *)&new_st[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(new_thread[i], NULL);
	mlx_put_image_to_window(st->mlxptr, st->winptr, st->imgptr, 0, 0);
	mlx_string_put(st->mlxptr, st->winptr, 490, 10, 0xCCCCCC, "H - Help");
	mlx_string_put(st->mlxptr, st->winptr, 490, 30, 0xCCCCCC, "Esc - Quit");
}

void			start(t_fract *st)
{
	st->complnum_to_pix = (st->max_re - st->min_re) / (WIN_H - 1);
	multithread(st);
}

void			init_struct(t_fract *st)
{
	st->min_re = -2.0;
	st->max_re = 2.0;
	st->min_im = -2.0;
	st->max_im = 2.0;
	st->pix_re = 0.0;
	st->pix_im = 0.0;
	st->col_coef = 1.0;
	st->max_iter = 20;
	st->j_re = 2.0;
	st->j_im = 2.0;
}

void			validate_input(t_fract *st, char *av)
{
	int			inp;

	inp = ft_atoi(av);
	if (inp == 1)
		st->fract_type = 1;
	else if (inp == 2)
		st->fract_type = 2;
	else if (inp == 3)
		st->fract_type = 3;
	else if (inp == 4)
		st->fract_type = 4;
	else if (inp == 5)
		st->fract_type = 5;
	else
		ft_error();
}

int				main(int ac, char **av)
{
	t_fract		st;

	if (ac == 2)
	{
		// st = (t_fract*)malloc(sizeof(t_fract));
		validate_input(&st, av[1]);
		st.mlxptr = mlx_init();
		st.winptr = mlx_new_window(st.mlxptr, WIN_W, WIN_H, "Fractal");
		st.imgptr = mlx_new_image(st.mlxptr, WIN_W, WIN_H);
		st.data = mlx_get_data_addr(st.imgptr, &st.bpp,\
					&st.size_line, &st.endian); 
		init_struct(&st);
		mlx_hook(st.winptr, 2, 0, keyboard, &st);
		mlx_hook(st.winptr, 4, 0, mouse, &st);
		if (st.fract_type == 2)
			mlx_hook(st.winptr, 6, 0, julia_control, &st);
		start(&st);
		mlx_loop(st.mlxptr);
	}
	else
		choose_help();
	return (0);
}
