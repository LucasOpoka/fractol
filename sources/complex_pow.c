/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_pow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lopoka@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:13:50 by lucas             #+#    #+#             */
/*   Updated: 2024/06/06 15:47:57 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

inline t_complex	ft_cplx_square(t_complex n)
{
	t_complex	res;

	res.r = (n.r * n.r) - (n.i * n.i);
	res.i = 2 * n.r * n.i;
	return (res);
}

inline t_complex	ft_cplx_cube(t_complex n)
{
	t_complex	res;

	res.r = (n.r * n.r * n.r) - 3 * (n.r * n.i * n.i);
	res.i = 3 * (n.r * n.r * n.i) - (n.i * n.i * n.i);
	return (res);
}
