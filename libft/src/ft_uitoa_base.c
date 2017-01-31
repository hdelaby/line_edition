/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:44:00 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/26 13:45:04 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(uintmax_t nb, int base, int upper)
{
	char		c;
	char		ret[50];
	int			i;

	i = 0;
	c = upper ? 'A' : 'a';
	if (base < 0 && base > 16)
		return (NULL);
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb != 0)
	{
		ret[i++] = nb % base > 9 ? c + (nb % base - 10) : '0' + (nb % base);
		nb /= base;
	}
	ret[i] = '\0';
	ft_strrev(ret);
	return (ft_strdup(ret));
}
