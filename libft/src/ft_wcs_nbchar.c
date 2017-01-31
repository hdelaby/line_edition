/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcs_nbchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:22:44 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/03 16:55:45 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Goes through a wchar string and counts the number of normal chars.
** Returns the number of chars
*/

size_t	ft_wcs_nbchar(wchar_t *wstr, char *str)
{
	int	ret;

	ret = 0;
	while (*wstr && *str)
	{
		ret += ft_strlen(str);
		str += 4;
		wstr += 1;
	}
	return (ret);
}
