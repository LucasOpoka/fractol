/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:02:39 by lopoka            #+#    #+#             */
/*   Updated: 2024/06/05 16:15:52 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

static inline size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}

static inline int	ft_atoi(const char *str)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + *str - 48;
		if (res < 0 && sign == 1)
			return (-1);
		if (res < 0 && sign == -1)
			return (0);
		str++;
	}
	return ((int)(res * sign));
}

double	ft_atof(const char *s)
{
	char	*str;
	double	int_part;
	double	float_part;
	int		i;

	str = (char *) s;
	int_part = (double) ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	float_part = (double)ft_atoi(str);
	i = ft_strlen(str);
	while (i--)
		float_part /= 10;
	if (int_part >= 0)
		return (int_part + float_part);
	else
		return (int_part - float_part);
}
