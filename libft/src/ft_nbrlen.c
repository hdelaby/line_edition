/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:54:29 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/28 14:12:22 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nbrlen(int nb)
{
	unsigned int	n;
	unsigned int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
		n = (unsigned int)nb;
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
