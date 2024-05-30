/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:47:44 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/30 17:48:28 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
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

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

void	ft_in_mandelbrot(mlx_image_t *img, int row, int col)
{
	t_complex	z;
	t_complex	c;
	int		color;

	z.r = 0;
	z.i = 0;
	c.r = map(row, -2, 2, 0, 800);
	c.i = map(col, 2, -2, 0, 800);

	for (int i = 0; i < 100; i++)
	{
		z = ft_complex_sum(ft_complex_square(z), c);
		if ((z.r * z.r + z.i * z.i) > 4)
		{
			color = map(i, 0x000000, 0xFFFFFF, 0, 100); // black white
			mlx_put_pixel(img, row, col, color);
			return ;
		}
	}
	mlx_put_pixel(img, row, col, 0x660066); //Purple
}

int main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(800, 800, "Fractol", true);
	if (!mlx)
		exit(1);
	img = mlx_new_image(mlx, 800, 800);
	if (!img)
	{
		mlx_close_window(mlx);
		free(mlx);
		exit(1);
	}

	for (int r = 0; r < 800; r++)
	{
		for (int c = 0; c < 800; c++)
		{
			ft_in_mandelbrot(img, r, c);
		}
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

