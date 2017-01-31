/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:33:26 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/29 15:42:00 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <locale.h>
#include "libft.h"

void	ft_putunicode(unsigned char *s)
{
	setlocale(LC_ALL, "");
	write(1, s, 1);
}
