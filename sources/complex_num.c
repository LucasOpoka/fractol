/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lopoka@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:50:22 by lucas             #+#    #+#             */
/*   Updated: 2024/06/03 22:20:44 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

inline t_complex	ft_cplx_sum(t_complex n1, t_complex n2)
{
	t_complex	res;

	res.r = n1.r + n2.r;
	res.i = n1.i + n2.i;
	return (res);
}

inline t_complex	ft_cplx_subt(t_complex n1, t_complex n2)
{
	t_complex	res;

	res.r = n1.r - n2.r;
	res.i = n1.i - n2.i;
	return (res);
}

inline t_complex	ft_cplx_rl_mult(int r, t_complex n)
{
	t_complex	res;

	res.r = r * n.r;
	res.i = r * n.i;
	return (res);
}

inline t_complex	ft_cplx_div(t_complex n1, t_complex n2)
{
	t_complex	res;

	res.r = (n1.r * n2.r + n1.i * n2.i) / (n2.r * n2.r + n2.i * n2.i);
	res.i = (n2.r * n1.i - n1.r * n2.i) / (n2.r * n2.r + n2.i * n2.i); 
	return (res);
}

inline t_complex ft_cplx_square(t_complex n)
{
	t_complex	res;

	res.r = n.r * n.r - n.i * n.i;
	res.i = 2 * n.r * n.i;
	return (res);
}

inline t_complex ft_cplx_cube(t_complex n)
{
	t_complex	res;

	res.r = (n.r * n.r * n.r) - 3 * (n.r * n.i * n.i);
	res.i = 3 * (n.r * n.r * n.i) - (n.i * n.i * n.i);
	return (res);
}
