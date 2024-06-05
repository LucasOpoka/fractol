/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lopoka@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:40:23 by lucas             #+#    #+#             */
/*   Updated: 2024/06/05 22:44:06 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

static inline void	ft_print_usage(void)
{
	ft_printf("Usage:\nFirst argument has to be one of those sets: ");
	ft_printf("Mandelbrot, Julia.\n");
	ft_printf("In case the Julia set was choosen provide two additional ");
	ft_printf("parameters: the real and imaginary parts of C.\n");
	ft_printf("To move the view use arrows, to zoom in and out use scroll.\n");
	ft_printf("To increase precision press Q to decrease it press W.\n");
	ft_printf("To change colour palette press C.\n");
	exit (1);
}

void	ft_validate_av(t_fract *stc, int ac, char **av)
{
	if (ac == 4 && !ft_strcmp(av[1], "Julia"))
	{
		stc->func = &ft_julia;
		stc->julia_cr = ft_atof(av[2]);
		stc->julia_ci = ft_atof(av[3]);
	}
	else if (ac == 2 && !ft_strcmp(av[1], "Mandelbrot"))
		stc->func = &ft_mandelbrot;
	else
		ft_print_usage();
}

void	ft_init_stc(t_fract *stc, int ac, char **av)
{
	ft_validate_av(stc, ac, av);
	stc->mlx = NULL;
	stc->img = NULL;
	stc->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!stc->mlx)
		ft_close(stc, 1);
	stc->img = mlx_new_image(stc->mlx, WIDTH, HEIGHT);
	if (!stc->img || mlx_image_to_window(stc->mlx, stc->img, 0, 0) < 0)
		ft_close(stc, 1);
	stc->min_x = -2;
	stc->max_x = 2;
	stc->min_y = -2;
	stc->max_y = 2;
	stc->zoom = 1;
	stc->precision = 100;
	stc->rand_r = ft_rand();
	stc->rand_g = ft_rand();
	stc->rand_b = ft_rand();
}
