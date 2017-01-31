/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:07:40 by hdelaby           #+#    #+#             */
/*   Updated: 2016/07/09 12:53:13 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int original;

	if ((nb == 0 && power == 0) || power == 0)
		return (1);
	if (power <= 0)
		return (0);
	original = nb;
	while (power != 1)
	{
		nb *= original;
		power--;
	}
	return (nb);
}
