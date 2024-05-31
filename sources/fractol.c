/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:47:44 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/31 15:23:03 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_show_img(t_fract *stc);

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
    	return (val * (stc->max_y - stc->min_y) / HEIGHT + stc->min_y);
	else	
    	return (val * (stc->max_x - stc->min_x) / WIDTH + stc->min_x);
}


double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
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
	c.r = ft_map(col, stc, 1);
	c.i = ft_map(row, stc, 0);

	for (int i = 0; i < stc->precision; i++)
	{
		z = ft_complex_sum(ft_complex_square(z), c);
		if ((z.r * z.r + z.i * z.i) > 4)
		{
			color = map(i, 0x000000, 0xFFFFFF, 0, 100); // black white
			mlx_put_pixel(stc->img, col, row, color);
			return ;
		}
	}
	mlx_put_pixel(stc->img, col, row, 0x660066); //Purple
}

void	ft_init_stc(t_fract *stc)
{
	stc->min_x = -2;
	stc->max_x = 2;
	stc->min_y = -2;
	stc->max_y = 2;
	stc->zoom = 1;
	stc->precision = 42;
}

void	ft_keyboard_hooks(mlx_key_data_t k_data, void *vd)
{
	t_fract	*stc;

	stc = (t_fract *)vd;
	if (k_data.key == MLX_KEY_ESCAPE && k_data.action == MLX_PRESS)
	{
		//todo free all, close
		exit (1);
	}
	if (k_data.key == MLX_KEY_UP && k_data.action == MLX_PRESS)
	{
		stc->min_y += 0.1 * stc->zoom;
		stc->max_y += 0.1 * stc->zoom;
		ft_show_img(stc);
	}
	if (k_data.key == MLX_KEY_DOWN && k_data.action == MLX_PRESS)
	{
		stc->min_y -= 0.1 * stc->zoom;
		stc->max_y -= 0.1 * stc->zoom;
		ft_show_img(stc);
	}
	if (k_data.key == MLX_KEY_LEFT && k_data.action == MLX_PRESS)
	{
		stc->min_x -= 0.1 * stc->zoom;
		stc->max_x -= 0.1 * stc->zoom;
		ft_show_img(stc);
	}
	if (k_data.key == MLX_KEY_RIGHT && k_data.action == MLX_PRESS)
	{
		stc->min_x += 0.1 * stc->zoom;
		stc->max_x += 0.1 * stc->zoom;
		ft_show_img(stc);
	}

}

void	ft_scroll_hooks(double xdelta, double ydelta, void *vd)
{
	(void) xdelta;
	(void) vd;
	if (ydelta > 0)
		puts("Down!");
	else if (ydelta < 0)
		puts("Up!");
}

void	ft_show_img(t_fract *stc)
{
	
	for (int r = 0; r < HEIGHT; r++)
	{
		for (int c = 0; c < WIDTH; c++)
		{
			ft_in_mandelbrot(stc, r, c);
		}
	}
	mlx_image_to_window(stc->mlx, stc->img, 0, 0);
}

int	main(void)
{
	t_fract		stc;

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
	ft_init_stc(&stc);
	ft_show_img(&stc);
	mlx_key_hook(stc.mlx, &ft_keyboard_hooks, &stc);
	mlx_scroll_hook(stc.mlx, &ft_scroll_hooks, NULL);
	mlx_loop(stc.mlx);
	return (0);
}

