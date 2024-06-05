/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lopoka@student.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:31:10 by lucas             #+#    #+#             */
/*   Updated: 2024/06/05 16:36:05 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h" 

long double	ft_map(long double val, t_fract *stc, int axis)
{
	if (!axis)
		return (val * (stc->max_y - stc->min_y) / HEIGHT + stc->min_y);
	else
		return (val * (stc->max_x - stc->min_x) / WIDTH + stc->min_x);
}

