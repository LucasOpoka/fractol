/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lopoka@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:59:53 by lucas             #+#    #+#             */
/*   Updated: 2024/06/04 15:09:14 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

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
