/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lopoka@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:04:11 by lucas             #+#    #+#             */
/*   Updated: 2024/06/04 15:11:32 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

static inline int	ft_rgbatoi(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

float	ft_rand(void)
{
	static unsigned long int	next;

	next = next * 1103515245 + 12345;
	return (((next / 65536) % 32768) / (float)32767);
}

int	ft_rand_color_map(int val, t_fract *stc)
{
	double	i;
	int		r;
	int		g;
	int		b;

	i = (double)val / stc->precision;
	r = (int)(stc->rand_r * i * 4242) % 255;
	g = (int)(stc->rand_g * i * 4242) % 255;
	b = (int)(stc->rand_b * i * 4242) % 255;
	return (ft_rgbatoi(r, g, b, 255));
}
