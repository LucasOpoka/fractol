/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lopoka@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:19:36 by lucas             #+#    #+#             */
/*   Updated: 2024/06/04 15:50:25 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

static inline void	ft_move_view(mlx_key_data_t k_data, t_fract *stc)
{
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
}

void	ft_keyboard_hooks(mlx_key_data_t k_data, void *vd)
{
	t_fract	*stc;

	stc = (t_fract *)vd;
	if (k_data.key == MLX_KEY_ESCAPE && k_data.action == MLX_PRESS)
		ft_close(stc, 0);
	ft_move_view(k_data, stc);
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

void	ft_close_hook(void *vd)
{
	ft_close((t_fract *)vd, 0);
}

void	ft_loop_hook(void *vd)
{
	ft_show_img((t_fract *) vd);
}
