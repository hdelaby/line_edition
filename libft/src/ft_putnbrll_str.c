/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:30:48 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/26 10:24:28 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_putnbrll_str(intmax_t nb, char *str, int i, int is_neg)
{
	uintmax_t n;

	n = (uintmax_t)nb;
	if (nb < 0)
		n = (uintmax_t)-nb;
	if (n > 9)
	{
		ft_putnbrll_str(n / 10, str, i + 1, is_neg);
		str[i] = (char)(n % 10) + '0';
	}
	else
	{
		str[i] = (char)n + '0';
		if (is_neg)
			str[++i] = '-';
		str[i + 1] = '\0';
	}
}
