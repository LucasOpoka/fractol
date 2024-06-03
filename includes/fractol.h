/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:06:19 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/03 15:25:07 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H
# include "../../MLX42/include/MLX42/MLX42.h"
# define WIDTH	1200
# define HEIGHT	1200
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
	int32_t		clr_in_set;
}	t_fract;

t_complex	ft_complex_sum(t_complex n1, t_complex n2);
t_complex	ft_complex_square(t_complex n);

#endif
