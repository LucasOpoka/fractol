/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lopoka@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:55:43 by lucas             #+#    #+#             */
/*   Updated: 2024/06/06 15:46:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

void	ft_show_img(t_fract *stc)
{
	int	res;
	int	color;
	int	row;
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
