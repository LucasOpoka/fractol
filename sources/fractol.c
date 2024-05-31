/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:47:44 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/31 13:00:09 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../includes/fractol.h"
#include <stdlib.h>

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

t_complex	ft_complex_sum(t_complex n1, t_complex n2)
{
	t_complex	res;

	res.r = n1.r + n2.r;
	res.i = n1.i + n2.i;
	return (res);
}

t_complex ft_complex_square(t_complex n)
{
	t_complex	res;

	res.r = n.r * n.r - n.i * n.i;
	res.i = 2 * n.r * n.i;
	return (res);
}



double ft_map(double val, t_fract *stc, int axis)
{
	if (!axis)
    	return (val * (stc->max_y - stc->min_y) / HEIGTH + stc->min_y);
	else	
    	return (val * (stc->max_x - stc->min_x) / WIDTH + stc->min_x);
}


double ft_map2(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

void	ft_in_mandelbrot(t_fract *stc, int row, int col)
{
	t_complex	z;
	t_complex	c;
	int		color;

	z.r = 0;
	z.i = 0;
	c.r = ft_map(row, stc, 0);
	c.i = ft_map(col, stc, 1);

	for (int i = 0; i < 100; i++)
	{
		z = ft_complex_sum(ft_complex_square(z), c);
		if ((z.r * z.r + z.i * z.i) > 4)
		{
			color = map(i, 0x000000, 0xFFFFFF, 0, 100); // black white
			mlx_put_pixel(stc->img, row, col, color);
			return ;
		}
	}
	mlx_put_pixel(stc->img, row, col, 0x660066); //Purple
}

int main(void)
{
	t_fract		stc;
	mlx_t		*mlx;
	mlx_image_t	*img;

	stc.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!stc.mlx)
		exit(1);
	stc.img = mlx_new_image(stc.mlx, WIDTH, HEIGHT);
	if (!stc.img)
	{
		mlx_close_window(stc.mlx);
		free(stc.mlx);
		exit(1);
	}

	for (int r = 0; r < HEIGHT; r++)
	{
		for (int c = 0; c < WIDTH; c++)
		{
			ft_in_mandelbrot(&stc, r, c);
		}
	}
	mlx_image_to_window(stc.mlx, stc.img, 0, 0);
	mlx_loop(stc.mlx);
	return (0);
}

