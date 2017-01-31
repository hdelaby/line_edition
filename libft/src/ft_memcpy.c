/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:18:55 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/06 16:06:35 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*d;
	unsigned long	*s;
	unsigned char	*dchar;
	unsigned char	*schar;

	d = (unsigned long *)dst;
	s = (unsigned long *)src;
	while ((n / 8) > 0)
	{
		*(d++) = *(s++);
		n -= 8;
	}
	dchar = (unsigned char *)d;
	schar = (unsigned char *)s;
	while (n--)
		*(dchar++) = *(schar++);
	return (dst);
}
