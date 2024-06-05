/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:58:37 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/17 10:00:43 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_prnt_p(t_printf *stc, unsigned long long pt)
{
	if (pt / 16 > 0)
		ft_prnt_p(stc, pt / 16);
	if (pt / 16 == 0)
		ft_prnt_s(stc, "0x");
	ft_prnt_c(stc, "0123456789abcdef"[pt % 16]);
}
