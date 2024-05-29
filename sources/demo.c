/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:10:47 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/29 15:37:47 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

t_complex	ft_complex_sum(t_complex n1, t_complex n2)
{
	t_complex	res;

	res.r = n1.r + n2.r;
	res.i = n1.i + n2.i;
	return (res);
}

t_complex ft_complex_square(t_complex n)
{
	t_complex	res;

	res.r = n.r * n.r - n.i * n.i;
	res.i = 2 * n.r * n.i;
	return (res);
}

#include <stdio.h>
int main(void)
{
	t_complex z;
	t_complex c;
	t_complex temp; 

	z.r = 0;
	z.i = 0;

	c.r = 0.2;
	c.i = 0.2;

	for (int i = 0; i < 10; i++)
	{
		z = ft_complex_sum(ft_complex_square(z), c);
		printf("Current r = %f	i = %f\n", z.r, z.i);
	}
	return 0;
}
