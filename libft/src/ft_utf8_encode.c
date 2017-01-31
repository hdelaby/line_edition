/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_encode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:01:22 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/03 16:56:45 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

/*
** Encodes a wchar_t argument into a 4 bytes string. Depending on the nb of
** bits needed, the operation is different. Unsupported values set the pointer
** to NULL as a signal that the encoding could not be done
*/

void	ft_utf8_encode(wchar_t c, unsigned char *b)
{
	if (c < 0x80)
		*b++ = c;
	else if (c < 0x800)
	{
		*b++ = 192 + c / 64;
		*b++ = 128 + c % 64;
	}
	else if (c - 0xd800u < 0x800)
		b = NULL;
	else if (c < 0x10000)
	{
		*b++ = 224 + c / 4096;
		*b++ = 128 + c / 64 % 64;
		*b++ = 128 + c % 64;
	}
	else if (c < 0x110000)
	{
		*b++ = 240 + c / 262144;
		*b++ = 128 + c / 4096 % 64;
		*b++ = 128 + c / 64 % 64;
		*b++ = 128 + c % 64;
	}
	else
		b = NULL;
}
