/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:38:14 by ldediu            #+#    #+#             */
/*   Updated: 2020/02/25 16:38:15 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

# define N_THREADS 20
# define WIN_W 600
# define WIN_H 600

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_SPACE 49
# define KEY_HELP 0x04
# define M_SCROLL_UP	4
# define M_SCROLL_DOWN	5
# define M_LEFT_CLICK	0x02
# define M_RIGHT_CLICK	0x01

typedef struct	s_fract
{
	void		*mlxptr;
	void		*winptr;
	void		*imgptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			fract_type;
	int			max_iter;
	float		min_re;
	float		max_re;
	float		min_im;
	float		max_im;
	float		complnum_to_pix;
	float		start;
	float		finish;
	float		pix_re;
	float		pix_im;
	float		col_coef;
	float		j_re;
	float		j_im;
}				t_fract;

typedef struct	s_complex
{
	float		re;
	float		im;
}				t_complex;

int				main(int ac, char **av);
void			validate_input(t_fract *st, char *av);
void			init_struct(t_fract *st);
void			start(t_fract *st);
void			multithread(t_fract *st);
void			draw(t_fract *st);
t_complex		init_complex_num(float re, float im);
t_complex		choose_fract(t_fract *st, float old_re, float old_im);
float			choose_more_fract_re(t_fract *st, float old_re, float old_im);
float			choose_more_fract_im(t_fract *st, float old_re, float old_im);
void			paint(t_fract *st, int i, int x, int y);
int				keyboard(int key, t_fract *st);
void			choose(int key, t_fract *st);
void			move(int key, t_fract *st);
int				mouse(int key, int x, int y, t_fract *st);
void			detalization(int key, t_fract *st);
int				julia_control(int x, int y, t_fract *st);
void			zoom(int key, int x, int y, t_fract *st);
void			ft_error(void);
void			ft_help(void);
void			choose_help(void);

#endif
