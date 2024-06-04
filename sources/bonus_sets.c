/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_sets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lopoka@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:35:05 by lucas             #+#    #+#             */
/*   Updated: 2024/06/04 15:35:29 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

inline int	ft_newton(t_fract *stc, int row, int col)
{
	t_complex	z;
	t_complex	z2;
	t_complex	one;
	int			i;

	i = 0;
	z.r = ft_map(col, stc, 1);
	z.i = ft_map(row, stc, 0);
	one.r = 1;
	one.i = 0;
	while (i < stc->precision)
	{
		z2 = ft_cplx_div(ft_cplx_subt(ft_cplx_cube(z), one),
				ft_cplx_rl_mult(3, ft_cplx_square(z)));
		z2 = ft_cplx_subt(z, z2);
		if (((z2.r - z.r) * (z2.r - z.r) + (z2.i - z.i) * (z2.i - z.i)) < 0.001)
			break ;
		else
		{
			z.i = z2.i;
			z.r = z2.r;
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
		z = ft_cplx_div(ft_cplx_sum(ft_cplx_square(z), z),
				ft_cplx_sum(ft_cplx_cube(z), c));
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
			return (stc->precision - i);
		i++;
	}
	return (0);
}

inline int	ft_cubic_julia(t_fract *stc, int row, int col)
{
	t_complex	z;
	t_complex	c;
	t_complex	negz;
	int			i;

	i = 0;
	c.r = 1.0008875;
	c.i = 0;
	z.r = ft_map(col, stc, 1);
	z.i = ft_map(row, stc, 0);
	while (i < stc->precision)
	{
		negz.r = -z.r;
		negz.i = -z.i;
		z = ft_cplx_sum(ft_cplx_subt(ft_cplx_cube(z), ft_cplx_square(negz)), c);
		if ((z.r * z.r + z.i * z.i) > 4)
			break ;
		i++;
	}
	return (i);
}
