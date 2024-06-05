/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:27:13 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/17 09:55:16 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static inline void	ft_prnt_f(t_printf *stc, char f, va_list *arg)
{
	if (f == 'c')
		ft_prnt_c(stc, va_arg(*arg, int));
	if (f == 's')
		ft_prnt_s(stc, va_arg(*arg, char *));
	if (f == 'p')
		ft_prnt_p(stc, va_arg(*arg, unsigned long long));
	if (f == 'd')
		ft_prnt_d(stc, va_arg(*arg, int));
	if (f == 'i')
		ft_prnt_d(stc, va_arg(*arg, int));
	if (f == 'u')
		ft_prnt_u(stc, va_arg(*arg, unsigned int));
	if (f == 'x')
		ft_prnt_lx(stc, va_arg(*arg, unsigned int));
	if (f == 'X')
		ft_prnt_ux(stc, va_arg(*arg, unsigned int));
	if (f == '%')
		ft_prnt_c(stc, '%');
	stc->i += 1;
}

static inline void	ft_init_printf_struct(t_printf *stc)
{
	stc->i = 0;
	stc->index = 0;
	stc->size = 100;
	stc->toadd = 100;
	stc->err = 0;
	stc->res = (char *) malloc(stc->size);
	if (!stc->res)
		stc->err = 1;
}

int	ft_printf(const char *s, ...)
{
	va_list		arg;
	t_printf	stc;

	ft_init_printf_struct(&stc);
	if (stc.err)
		return (-1);
	va_start(arg, s);
	while (s[stc.i])
	{
		if (s[stc.i] == '%')
		{
			if (!s[stc.i + 1])
				break ;
			ft_prnt_f(&stc, s[stc.i + 1], &arg);
		}
		else
			ft_prnt_c(&stc, s[stc.i]);
		if (stc.err)
			return (-1);
		stc.i += 1;
	}
	va_end(arg);
	stc.i = write(1, stc.res, stc.index);
	free(stc.res);
	return (stc.i);
}
