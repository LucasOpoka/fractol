/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:06:19 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/04 15:17:01 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include "../sources/MLX42/include/MLX42/MLX42.h"
# define WIDTH	1200
# define HEIGHT	1200
# define abs(x) ((x)<0 ? -(x) : (x))

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_fract
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			(*func)(struct s_fract *stc, int row, int col);
	int			precision;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	double		zoom;
	int32_t		mouse_x;		
	int32_t		mouse_y;
	double		rand_r;
	double		rand_g;
	double		rand_b;
}	t_fract;

int	ft_mandelbrot(t_fract *stc, int row, int col);
int	ft_julia(t_fract *stc, int row, int col);
int	ft_newton(t_fract *stc, int row, int col);
int	ft_bow(t_fract *stc, int row, int col);
int	ft_mandelbrot3(t_fract *stc, int row, int col);
int	ft_cubic_julia(t_fract *stc, int row, int col);

void	ft_show_img(t_fract *stc);
float ft_rand(void);
int	ft_rand_color_map(int val, t_fract *stc);

void	ft_loop_hook(void *vd);
void	ft_close_hook(void *vd);
void	ft_keyboard_hooks(mlx_key_data_t k_data, void *vd);
void	ft_scroll_hooks(double xdelta, double ydelta, void *vd);


void	ft_init_stc(t_fract *stc);
double ft_map(double val, t_fract *stc, int axis);

t_complex	ft_cplx_sum(t_complex n1, t_complex n2);
t_complex	ft_cplx_subt(t_complex n1, t_complex n2);
t_complex	ft_cplx_rl_mult(int r, t_complex n2);
t_complex	ft_cplx_div(t_complex n1, t_complex n2);
t_complex	ft_cplx_square(t_complex n);
t_complex	ft_cplx_cube(t_complex n);

void	ft_close(t_fract *stc, int code);

#endif
