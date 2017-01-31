/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:25:11 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/03 16:54:55 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Here the function works with wstr determining the wchar and str being the
** encoded 4bytes char * corresponding to that wchar. The function assumes that
** str contains the UTF8 encoded wstr.
*/

void	ft_putwstr(wchar_t *wstr, char *str)
{
	while (*wstr && *str)
	{
		ft_putstr(str);
		str += 4;
		wstr += 1;
	}
}
