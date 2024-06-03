/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lopoka@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:56:16 by lucas             #+#    #+#             */
/*   Updated: 2024/06/03 23:56:53 by lucas            ###   ########.fr       */
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
		z = ft_cplx_sum(ft_cplx_square(z), c);
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
		z = ft_cplx_sum(ft_cplx_square(z), c);
		if ((z.r * z.r + z.i * z.i) > 4)
			break ;
		i++;
	}
	return (i);
}

inline int	ft_newton(t_fract *stc, int row, int col)
{
	t_complex	z;
	t_complex	z_new;
	t_complex	one;
	int			i;
	
	i = 0;
	z.r = ft_map(col, stc, 1);
	z.i = ft_map(row, stc, 0);
	one.r = 1;
	one.i = 0;
	while (i < stc->precision)
	{
		z_new = ft_cplx_div(ft_cplx_subt(ft_cplx_cube(z), one), ft_cplx_rl_mult(3, ft_cplx_square(z)));
		z_new = ft_cplx_subt(z, z_new);
		if (((z_new.r - z.r) * (z_new.r - z.r) + (z_new.i - z.i) * (z_new.i - z.i)) < 0.001)
			break ;
		else
		{
			z.i = z_new.i;
			z.r = z_new.r;
		}
		i++;
	}
	return (i);

}

inline int	ft_bow(t_fract *stc, int row, int col)
{
	t_complex	z;
	t_complex	c;
	int			i;
	
	i = 0;
	c.r = 0;
	c.i = 0;
	z.r = ft_map(col, stc, 1);
	z.i = ft_map(row, stc, 0);
	while (i < stc->precision)
	{
		z = ft_cplx_div(ft_cplx_sum(ft_cplx_square(z), z), ft_cplx_sum(ft_cplx_cube(z), c));
		if ((z.r * z.r + z.i * z.i) > 4)
			break ;
		i++;
	}
	return (i);

}

inline int	ft_mandelbrot3(t_fract *stc, int row, int col)
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
		z = ft_cplx_sum(ft_cplx_cube(z), c);
		if ((z.r * z.r + z.i * z.i) > 4)
			return (stc->precision - i) ;
		i++;
	}
	return (0);


}
