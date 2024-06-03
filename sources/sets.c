/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lopoka@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:56:16 by lucas             #+#    #+#             */
/*   Updated: 2024/06/03 17:12:30 by lucas            ###   ########.fr       */
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

inline int	ft_mandelbrot(t_fract *stc, int row, int col)
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

inline int	ft_julia(t_fract *stc, int row, int col)
{
	t_complex	z;
	t_complex	c;
	int			i;
	
	i = 0;
	z.r = ft_map(col, stc, 1);
	z.i = ft_map(row, stc, 0);
	c.r = -0.7269;
	c.i = 0.1889;
	while (i < stc->precision)
	{
		z = ft_complex_sum(ft_complex_square(z), c);
		if ((z.r * z.r + z.i * z.i) > 4)
			break ;
		i++;
	}
	return (i);
}

