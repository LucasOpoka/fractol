/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:58:19 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/17 10:01:38 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_prnt_s(t_printf *stc, char *str)
{
	int	i;

	if (!str)
		ft_prnt_s(stc, "(null)");
	else
	{
		i = 0;
		while (str[i])
			ft_prnt_c(stc, str[i++]);
	}
}
