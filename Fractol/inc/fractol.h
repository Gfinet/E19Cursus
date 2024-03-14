/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/03/14 02:13:33 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../Printf/ft_printf.h"
# include "../mlx/mlx.h"
# include "keycode.h"
# include <math.h>
# include <stdio.h>

#ifndef WIN_HEIGHT
# define WIN_HEIGHT 300
#endif
#ifndef COEF
# define COEF WIN_HEIGHT /1.3
#endif
#ifndef WIN_WIDTH
# define WIN_WIDTH WIN_HEIGHT * 1.5
#endif

//2560 × 1664
//1920 x 1080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vec {
	double x;
	double y;
}	t_vec;

typedef struct s_zoom 
{
	double decal;
	int move;
	int zoom;
	unsigned int color;
	unsigned int b_color;
	int julia_mandel;
} t_zoom;

typedef struct s_fract
{
	t_data img;
	void *mlx;
	void *win;
	t_vec z;
	t_vec c;
	t_zoom mv;
	double	coef;
	int max_it;
	int start_x;
	int start_y;

}	t_fract;

t_fract *fract_init(int argc, char **arg);
void 	set_dec_move(t_fract *f);
void	set_null(t_fract *f, int j_m);
void 	print_option();
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

double mod2(t_vec z);
double compute_it(t_fract *f);
void draw_fract(t_fract *f);

t_vec compute_next(t_vec cur, t_vec cons);

int esc_handle(t_fract *f);
int	key_event(int keycode, t_fract *f);
int mouse_event(int keycode, int x, int y, t_fract *f);

#endif