/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:31:52 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/07 09:45:21 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uchar;
	unsigned long	ulong;
	unsigned char	*schar;
	unsigned long	*slong;

	uchar = (unsigned char)c;
	ulong = (unsigned char)uchar;
	ulong = (ulong << 8) | (ulong << 16) | (ulong << 24) | ulong;
	ulong = (ulong << 32) | ulong;
	slong = (unsigned long *)b;
	while ((len / 8) > 0)
	{
		*(slong++) = ulong;
		len -= 8;
	}
	schar = (unsigned char *)slong;
	while (len)
	{
		*(schar++) = (unsigned char)c;
		len--;
	}
	return (b);
}
