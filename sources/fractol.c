/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:47:44 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/04 15:18:51 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_fract		stc;

	ft_init_stc(&stc, ac, av);
	mlx_close_hook(stc.mlx, &ft_close_hook, &stc);
	mlx_key_hook(stc.mlx, &ft_keyboard_hooks, &stc);
	mlx_scroll_hook(stc.mlx, &ft_scroll_hooks, &stc);
	mlx_loop_hook(stc.mlx, ft_loop_hook, &stc);
	mlx_loop(stc.mlx);
	mlx_terminate(stc.mlx);
	return (0);
}
