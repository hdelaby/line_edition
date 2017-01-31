/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:52:28 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/26 10:08:11 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	char	*end;
	char	tmp;

	if (!str || !*(str))
		return ;
	end = str + ft_strlen(str) - 1;
	while (end > str)
	{
		tmp = *str;
		*str = *end;
		*end = tmp;
		++str;
		--end;
	}
}
