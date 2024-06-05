/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:54:39 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/17 10:04:05 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_printf
{
	char	*res;
	size_t	i;
	size_t	index;
	size_t	size;
	size_t	err;
	size_t	toadd;
}	t_printf;

int		ft_printf(const char *s, ...);
void	ft_prnt_c(t_printf *stc, int c);
void	ft_prnt_s(t_printf *stc, char *str);
void	ft_prnt_p(t_printf *stc, unsigned long long pt);
void	ft_prnt_d(t_printf *stc, int nb);
void	ft_prnt_u(t_printf *stc, unsigned int nb);
void	ft_prnt_lx(t_printf *stc, unsigned int n);
void	ft_prnt_ux(t_printf *stc, unsigned int n);
void	*ft_realloc(void *src, size_t old_s, size_t add_s);
void	ft_printf_realloc(t_printf *stc);
void	ft_prnt_add(t_printf *stc, int c);

#endif
