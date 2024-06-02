/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:47:44 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/02 21:47:05 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void	ft_show_img(t_fract *stc);
void	ft_close(t_fract *stc, int code);
int		ft_rgbatoi(int r, int g, int b, int a);
float ft_rand(void);

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

int	ft_mandelbrot(t_fract *stc, int row, int col)
{
	t_complex	z;
	t_complex	c;
	int			i;
	
	i = 0;
	z.r = 0;
	z.i = 0;
	c.r = ft_map(col, stc, 1);
	c.i = ft_map(row, stc, 0);
	while (i < stc->precision)
	{
		z = ft_complex_sum(ft_complex_square(z), c);
		if ((z.r * z.r + z.i * z.i) > 4)
			break ;
		i++;
	}
	return (i);
}

void	ft_init_stc(t_fract *stc)
{
	stc->mlx = NULL;
	stc->img = NULL;
	stc->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!stc->mlx)
		exit(1);
	stc->img = mlx_new_image(stc->mlx, WIDTH, HEIGHT);
	if (!stc->img || mlx_image_to_window(stc->mlx, stc->img, 0, 0) < 0)
	{
		mlx_close_window(stc->mlx);
		mlx_terminate(stc->mlx);
		exit(1);
	}
	stc->func = &ft_mandelbrot;
	stc->min_x = -2;
	stc->max_x = 2;
	stc->min_y = -2;
	stc->max_y = 2;
	stc->zoom = 1;
	stc->precision = 100;
	stc->rand_r = ft_rand();
	stc->rand_g = ft_rand();
	stc->rand_b = ft_rand();
	stc->clr_in_set = ft_rgbatoi(245, 40, 145, 255);
}

void	ft_keyboard_hooks(mlx_key_data_t k_data, void *vd)
{
	t_fract	*stc;

	stc = (t_fract *)vd;
	if (k_data.key == MLX_KEY_ESCAPE && k_data.action == MLX_PRESS)
		ft_close(stc, 0);
	if (k_data.key == MLX_KEY_UP && k_data.action == MLX_PRESS)
	{
		stc->min_y -= 0.1 * stc->zoom;
		stc->max_y -= 0.1 * stc->zoom;
	}
	if (k_data.key == MLX_KEY_DOWN && k_data.action == MLX_PRESS)
	{
		stc->min_y += 0.1 * stc->zoom;
		stc->max_y += 0.1 * stc->zoom;
	}
	if (k_data.key == MLX_KEY_LEFT && k_data.action == MLX_PRESS)
	{
		stc->min_x -= 0.1 * stc->zoom;
		stc->max_x -= 0.1 * stc->zoom;
	}
	if (k_data.key == MLX_KEY_RIGHT && k_data.action == MLX_PRESS)
	{
		stc->min_x += 0.1 * stc->zoom;
		stc->max_x += 0.1 * stc->zoom;
	}
	if (k_data.key == MLX_KEY_Q && k_data.action == MLX_PRESS)
		stc->precision *= 1.1;
	if (k_data.key == MLX_KEY_W && k_data.action == MLX_PRESS)
		stc->precision *= 0.9;
	if (k_data.key == MLX_KEY_C && k_data.action == MLX_PRESS)
	{
		stc->rand_r = ft_rand();
		stc->rand_g = ft_rand();
		stc->rand_b = ft_rand();
	}
}

void	ft_scroll_hooks(double xdelta, double ydelta, void *vd)
{	
	t_fract	*stc;
	double	x_scaled;
	double	y_scaled;
	double	modifier;

	(void) xdelta;
	stc = (t_fract *)vd;
	if (ydelta != 0)
	{
		mlx_get_mouse_pos(stc->mlx, &stc->mouse_x, &stc->mouse_y);
		if (ydelta > 0)
			modifier = 1.1;
		else
			modifier = 0.9;
		stc->zoom *= modifier;
		x_scaled = ft_map(stc->mouse_x, stc, 1) * (1 - modifier);
		y_scaled = ft_map(stc->mouse_y, stc, 0) * (1 - modifier);
		stc->max_x = stc->max_x * modifier + x_scaled;
		stc->min_x = stc->min_x * modifier + x_scaled;
		stc->max_y = stc->max_y * modifier + y_scaled;
		stc->min_y = stc->min_y * modifier + y_scaled;
	}
}

int32_t	ft_rgbatoi(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

float ft_rand(void)
{
	static unsigned long int	next;

    next = next * 1103515245 + 12345;
    return ((float)((next / 65536) % 32768) / 32768);
}

int	ft_rand_color_map(int val, t_fract *stc)
{
	int i;
	int r;
	int	g;
	int	b;

	i = (float)val / stc->precision * 255;
	r = sin(stc->rand_r * i * 8) * 127 + 128; 
	g = sin(stc->rand_g * i * 8) * 127 + 128; 
	b = sin(stc->rand_b * i * 8) * 127 + 128; 
	return (ft_rgbatoi(r, g, b, 255));
}

void	ft_show_img(t_fract *stc)
{
	int	res;
	int	color;
	int row;
	int	col;
	
	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			res = stc->func(stc, row, col);
			color = ft_rand_color_map(res, stc);
			mlx_put_pixel(stc->img, col++, row, color);
		}
		row++;
	}
	mlx_image_to_window(stc->mlx, stc->img, 0, 0);
}

void	ft_close(t_fract *stc, int code)
{
	if (stc->img)
		mlx_delete_image(stc->mlx, stc->img);
	if (stc->mlx)
	{
		mlx_close_window(stc->mlx);
		mlx_terminate(stc->mlx);
	}
	exit (code);
}

void	ft_close_hook(void *vd)
{
	ft_close((t_fract *)vd, 0);
}

void	ft_loop_hook(void *vd)
{
	ft_show_img((t_fract *) vd);
}

int	main(void)
{
	t_fract		stc;

	ft_init_stc(&stc);
	mlx_close_hook(stc.mlx, &ft_close_hook, &stc);
	mlx_key_hook(stc.mlx, &ft_keyboard_hooks, &stc);
	mlx_scroll_hook(stc.mlx, &ft_scroll_hooks, &stc);
	mlx_loop_hook(stc.mlx, ft_loop_hook, &stc);
	mlx_loop(stc.mlx);
	mlx_terminate(stc.mlx);
	return (0);
}

