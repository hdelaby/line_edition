/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzerostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 09:16:41 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/30 09:17:49 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putzerostr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar(0);
	while (*str)
		ft_putchar(*str++);
}
