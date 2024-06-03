/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:47:44 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/03 16:57:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

double ft_map(double val, t_fract *stc, int axis)
{
	if (!axis)
    	return (val * (stc->max_y - stc->min_y) / HEIGHT + stc->min_y);
	else	
    	return (val * (stc->max_x - stc->min_x) / WIDTH + stc->min_x);
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

