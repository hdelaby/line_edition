/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:54:55 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/23 15:52:11 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void			ft_putnbr_str(int nb, char *str, int i)
{
	unsigned int n;

	i--;
	n = (unsigned int)nb;
	if (nb < 0)
	{
		str[0] = '-';
		n = (unsigned int)-nb;
	}
	if (n > 9)
	{
		ft_putnbr_str(n / 10, str, i);
		str[i] = (char)(n % 10) + '0';
	}
	else
		str[i] = (char)n + '0';
}

static unsigned int	ft_nbrlen1(int nb)
{
	unsigned int	n;
	unsigned int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
		n = (unsigned int)-nb;
	}
	else
		n = (unsigned int)nb;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (!n)
		return (ft_strdup("0"));
	else
	{
		if ((str = ft_strnew(ft_nbrlen1(n))) == NULL)
			return (NULL);
		len = ft_nbrlen1(n);
		ft_putnbr_str(n, str, len);
	}
	return (str);
}
