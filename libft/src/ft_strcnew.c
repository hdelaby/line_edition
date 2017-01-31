/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:37:43 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/28 11:38:34 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcnew(size_t size, int c)
{
	char	*ret;

	ret = ft_strnew(size);
	if (ret)
		ft_memset(ret, c, size);
	return (ret);
}
