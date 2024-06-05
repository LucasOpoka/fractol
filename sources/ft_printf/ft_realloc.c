/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:47:54 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/16 17:48:35 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	*ft_realloc(void *src, size_t old_s, size_t add_s)
{
	size_t	i;
	void	*dst;
	char	*c_dst;
	char	*c_src;

	dst = (void *) malloc(old_s + add_s);
	if (!dst)
	{
		free (src);
		return (0);
	}
	c_dst = (char *) dst;
	c_src = (char *) src;
	i = 0;
	while (i < old_s)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	free(src);
	return (dst);
}
