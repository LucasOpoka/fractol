/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:06:19 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/06 16:47:59 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include "../sources/MLX42/include/MLX42/MLX42.h"
# include "../sources/ft_printf/ft_printf.h"
# define WIDTH	1200
# define HEIGHT	1200

typedef struct s_complex
{
	long double	r;
	long double	i;
}	t_complex;

typedef struct s_fract
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				(*func)(struct s_fract *stc, int row, int col);
	int				precision;
	long double		min_x;
	long double		max_x;
	long double		min_y;
	long double		max_y;
	long double		zoom;
	int32_t			mouse_x;		
	int32_t			mouse_y;
	double			rand_r;
	double			rand_g;
	double			rand_b;
	long double		julia_cr;
	long double		julia_ci;
}	t_fract;

int			ft_mandelbrot(t_fract *stc, int row, int col);
int			ft_julia(t_fract *stc, int row, int col);
int			ft_newton(t_fract *stc, int row, int col);
int			ft_bow(t_fract *stc, int row, int col);
int			ft_mandelbrot3(t_fract *stc, int row, int col);
int			ft_cubic_julia(t_fract *stc, int row, int col);

void		ft_show_img(t_fract *stc);
float		ft_rand(void);
int			ft_rand_color_map(int val, t_fract *stc);

void		ft_loop_hook(void *vd);
void		ft_close_hook(void *vd);
void		ft_keyboard_hooks(mlx_key_data_t k_data, void *vd);
void		ft_scroll_hooks(double xdelta, double ydelta, void *vd);

int			ft_strcmp(const char *s1, const char *s2);
long double	ft_atold(const char *s);

void		ft_init_stc(t_fract *stc, int ac, char **av);
long double	ft_map(long double val, t_fract *stc, int axis);

t_complex	ft_cplx_sum(t_complex n1, t_complex n2);
t_complex	ft_cplx_subt(t_complex n1, t_complex n2);
t_complex	ft_cplx_rl_mult(int r, t_complex n2);
t_complex	ft_cplx_div(t_complex n1, t_complex n2);
t_complex	ft_cplx_square(t_complex n);
t_complex	ft_cplx_cube(t_complex n);

void		ft_close(t_fract *stc, int code);

#endif
