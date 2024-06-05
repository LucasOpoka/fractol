/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:59:09 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/17 08:44:54 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_printf_realloc(t_printf *stc)
{
	if (stc->index >= stc->size)
	{
		stc->res = ft_realloc(stc->res, stc->size, stc->toadd);
		if (!stc->res)
			stc->err = 1;
		stc->size += stc->toadd;
	}
}
