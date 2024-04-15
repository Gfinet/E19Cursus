/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/15 15:24:38 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../Printf/ft_printf.h"
# include "../mlx/mlx.h"
# include "keycode.h"
# include <math.h>

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 800
# endif
# ifndef WIN_WIDTH
#  define WIN_WIDTH 1200
# endif

//300x450
//600x900
//1000x1500

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_option
{
	double			decal;
	int				julia_mandel;
	int				follow_m;
	unsigned int	color;
	unsigned int	b_color;
}	t_option;

typedef struct s_fract
{
	t_data		img;
	void		*mlx;
	void		*win;
	t_option	mv;
	t_vec		z;
	t_vec		c;
	int			max_it;
	double		coef;
	double		start_x;
	double		start_y;

}	t_fract;

//main_fractol.c
void	set_dec_move(t_fract *f);
void	set_null(t_fract *f, int j_m);
t_fract	*fract_init(int argc, char **arg);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//mandelbrot.c
t_vec	compute_next(t_vec cur, t_vec cons, int burn);
double	compute_mand(t_fract *f);
double	compute_julia(t_fract *f);
double	compute_burning(t_fract *f);
void	draw_fract(t_fract *f);

//handle_event.c
void	print_option(void);
int		esc_handle(t_fract *f);
int		key_event(int keycode, t_fract *f);
void	key_event_next(int keycode, t_fract *f);
int		mouse_event(int keycode, int x, int y, t_fract *f);

//zoom.c
void	zoom_in(int x, int y, t_fract *f);
void	zoom_out(int x, int y, t_fract *f);
void	set_color(t_fract *f, int x, int y, int it);
#endif